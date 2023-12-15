import pololu_connection as pololu

NINETYRIGHT = 85
NINETYLEFT = 84
THREESIXTYRIGHT = 357
THREESIXTYLEFT = 354
ONEEIGHTYRIGHT = 175
ONEEIGHTYLEFT = 175

ONEFORWARD = 300

pololu_names = ["alex", "ashley", "miffy", "manas"]


pololu_prefix = "pololu_"

speed = 1.0
index = 0


for name in pololu_names:
    robot_name = pololu_prefix + name
    pololu.clear_file(robot_name + "_replies.txt")


commands = [f"MOVE_BACKWARD:{ONEFORWARD}",
            f"TURN_RIGHT:{NINETYRIGHT}",
            f"MOVE_FORWARD:{ONEFORWARD}",
            f"TURN_LEFT:{ONEEIGHTYLEFT}",
            f"MOVE_FORWARD:{ONEFORWARD * 2}",
            f"TURN_RIGHT:{ONEEIGHTYRIGHT}",
            f"MOVE_FORWARD:{ONEFORWARD}",
            f"TURN_LEFT:{NINETYLEFT}",
            f"MOVE_FORWARD:{ONEFORWARD}"]

# commands = [f"MOVE_FORWARD:{ONEFORWARD * 3}",
#             f"MOVE_BACKWARD:{ONEFORWARD * 3}"]




# # SAME_MOVES
while index < len(commands):
    for name in pololu_names:
        transmitted_message = commands[index]
        robot_name = pololu_prefix + name
        if (transmitted_message != ""):
            pololu.write_message(robot_name, transmitted_message)

    index += 1

    for name in pololu_names:
        robot_name = pololu_prefix + name
        received_mssage = pololu.read_message(robot_name)
        while not received_mssage:
            received_mssage = pololu.read_message(robot_name)
        pololu.clear_file(robot_name + "_replies.txt")
        print(f"{name.title()} replied: {received_mssage}")

moving = [f"TURN_RIGHT:{NINETYRIGHT}",
        f"MOVE_FORWARD:{ONEFORWARD}",
        f"MOVE_FORWARD:{ONEFORWARD}",
        f"TURN_LEFT:{ONEEIGHTYLEFT}",
        f"MOVE_FORWARD:{ONEFORWARD}",
        f"MOVE_FORWARD:{ONEFORWARD}",
        f"TURN_RIGHT:{ONEEIGHTYRIGHT}",
        f"TURN_LEFT:{NINETYLEFT}"]

idle = [
        f"TURN_RIGHT:{NINETYRIGHT}",
        f"TURN_LEFT:{THREESIXTYLEFT}",
        f"TURN_RIGHT:{THREESIXTYLEFT}",
        f"TURN_LEFT:{THREESIXTYRIGHT}",
        f"TURN_RIGHT:{THREESIXTYLEFT}",
        f"TURN_LEFT:{THREESIXTYRIGHT}",
        f"TURN_RIGHT:{THREESIXTYRIGHT}",
        f"TURN_LEFT:{NINETYLEFT}"
    ]

commands_dict = {
    "alex": moving + idle + idle + idle,
    "ashley": idle + moving + idle + idle,
    "miffy": idle + idle + moving + idle,
    "manas": idle + idle + idle + moving,
}

# DIFFERENT MOVES
# while index < len(commands_dict["alex"]):
#     for name in pololu_names:
#         transmitted_message = commands_dict[name][index]
#         robot_name = pololu_prefix + name
#         if (transmitted_message != ""):
#             pololu.write_message(robot_name, transmitted_message)

#     index += 1

#     for name in pololu_names:
#         robot_name = pololu_prefix + name
#         received_mssage = pololu.read_message(robot_name)
#         while not received_mssage:
#             received_mssage = pololu.read_message(robot_name)
#         pololu.clear_file(robot_name + "_replies.txt")
#         print(f"{name.title()} replied: {received_mssage}")


    