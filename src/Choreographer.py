# Assume we are recieving messages from pololu in (name, (x, y))
# We send (name, "commands")
# "[DRIVE,10, ]"

import random
import math

# Constants
MAX_SPEED = 0.5
AVOID_RADIUS = 50

# Agent class
class Agent:
    def __init__(self, x, y):
        self.x = x
        self.y = y
        self.vx = random.uniform(-MAX_SPEED, MAX_SPEED)
        self.vy = random.uniform(-MAX_SPEED, MAX_SPEED)

    def calculate_next_position(self, agents):
        next_x = self.x + self.vx
        next_y = self.y + self.vy

        # Avoid other agents
        for other_agent in agents:
            if other_agent != self:
                dx = other_agent.x - next_x
                dy = other_agent.y - next_y
                distance = math.sqrt(dx ** 2 + dy ** 2)

                if distance < AVOID_RADIUS:
                    angle = math.atan2(dy, dx)
                    next_x -= 0.1 * math.cos(angle)
                    next_y -= 0.1 * math.sin(angle)

        # Boundaries check (optional)
        # You can add logic here to handle boundaries if needed

        return next_x, next_y

# Example usage
agents = [Agent(random.uniform(0, 800), random.uniform(0, 600)) for _ in range(10)]

# Get next positions for each agent
for agent in agents:
    next_x, next_y = agent.calculate_next_position(agents)
    print(f"Agent at ({agent.x}, {agent.y}) will move to ({next_x}, {next_y})")

    # write a function that takes in the next (x, y) and turns it into a list of commands to send to pololu