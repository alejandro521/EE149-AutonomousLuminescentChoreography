import pololu_connection as pololu
import time

pololu_names = ["alex"]
pololu_prefix = "pololu_"

# for name in pololu_names:
#     pololu.set_name(pololu_prefix + name, name)
while True:
    for name in pololu_names:
        robot_name = pololu_prefix + name

        transmitted_message = input(f"Message to {name.title()}: ")
        if (transmitted_message != ""):
            pololu.write_message(robot_name, transmitted_message)

        received_mssage = pololu.read_message(robot_name)
        while not received_mssage:
            received_mssage = pololu.read_message(robot_name)
        print(f"{name.title()} replied: {received_mssage}")
    