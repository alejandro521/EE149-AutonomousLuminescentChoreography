import asyncio
import os
import sys
from bleak import BleakScanner
from bleak import BleakClient

transmit_filename_suffix = "_commands.txt"
receive_filename_suffix = "_replies.txt"


def write_message(robot_name, message):
    with open(robot_name + transmit_filename_suffix, "w") as file:
        file.write(message)

def read_message(robot_name):
    try:
        with open(robot_name + receive_filename_suffix, "r") as file:
            message = file.read()
    except FileNotFoundError:
        message = ""

    clear_file(robot_name + receive_filename_suffix)
    return message
    

def set_name(robot_name, name):
    write_message(robot_name, "SET_NAME:"+ name)


async def send_message(client, serial_characteristic, message):
    # Convert the message to bytes
    carriage_return_byte = b'\r'
    message_bytes = message.encode('utf-8')
    # Write the message to the HM-10's serial characteristic
    await client.write_gatt_char(serial_characteristic, message_bytes)
    await client.write_gatt_char(serial_characteristic, carriage_return_byte)
    print(f"Sent message: {message}")

received_data = ""
async def receive_message(sender, data):
    global received_data
    global receive_filename
    clear_file(receive_filename)
    received_data += data.decode('utf-8')
    if received_data.endswith('\r'):
        with open(receive_filename, "w") as file:
            file.write(received_data)

        print(f"Received complete message: {received_data}")
        received_data = ""

def clear_file(filename):
    open(filename, 'w').close()

def ensure_file_exists(filename):
    """Ensure that the specified file exists. Create it if it doesn't."""
    if not os.path.exists(filename):
        open(filename, 'w').close()

async def monitor_files_for_messages(commands_file, client):
    serial_characteristic = "None"
    for service in client.services:
        print(f"Service: {service.uuid}")
        for characteristic in service.characteristics:
            serial_characteristic = characteristic.uuid
            print(f"Serial Characteristic: {serial_characteristic}")
    
    await client.start_notify(serial_characteristic, receive_message)
    print("Monitoring messages...")
    while True:
        await asyncio.sleep(0.05)  # Sleep for 1 second
        try:
            with open(commands_file, 'r') as file:
                content = file.read()
                if content:
                    await send_message(client, serial_characteristic, content) # New message received, send it to the device
                    clear_file(commands_file) # Clear the file after sending the message
        except FileNotFoundError:
            continue  # File not found, keep checking

async def find_device(device_name):
    devices = await BleakScanner.discover()
    for device in devices:
        if device.name == device_name:
            return device
    return None

async def connect_and_maintain(address, commands_file):
    async with BleakClient(address) as client:
        if client.is_connected:
            print(f"Connected to {address}")
            await client.get_services() # Perform service discovery
            await monitor_files_for_messages(commands_file, client)
        else:
            print("Failed to connect.")

if __name__ == "__main__":
    global receive_filename
    device_name = sys.argv[1]
    transmit_filename = device_name.lower() + transmit_filename_suffix
    ensure_file_exists(transmit_filename)

    receive_filename = device_name.lower() + receive_filename_suffix
    ensure_file_exists(receive_filename)

    loop = asyncio.get_event_loop()
    target_device = loop.run_until_complete(find_device(device_name))

    if target_device:
        print(f"Found target device: {target_device.name}, Address: {target_device.address}")
        loop.run_until_complete(connect_and_maintain(target_device.address, transmit_filename))
    else:
        print("Target device not found.")