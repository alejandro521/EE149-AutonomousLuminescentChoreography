import pololu_connection as pololu
import time

pololu_names = ["alex", "ashley"]
pololu_prefix = "pololu_"

for name in pololu_names:
    pololu.set_name(pololu_prefix + name, name)
counter = 0
while True:
    for name in pololu_names:
        robot_name = pololu_prefix + name
        message = f"{counter}"
        pololu.write_message(robot_name, message)
    counter += 1
    time.sleep(1)
