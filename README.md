# Two-Wheeled Robot Control System (ROS1)

This ROS1 project implements a **communication and control system** for a two-wheeled ground robot that navigates toward a target. The system integrates multiple ROS nodes to monitor positions, compute control commands, and provide real-time feedback to the user.

---

## Project Overview

- **Goal:** Move a two-wheeled robot to a specified target using ROS1 nodes and a proportional controller.
- **Nodes:**
  - `Robot` – publishes the robot’s current position.
  - `Camera` – publishes the target position.
  - `Controller` – calculates angular and forward velocities based on robot and target positions.
  - `UI` – displays feedback messages including velocities and position data.
- **Custom ROS Messages:**
  - `ObjectPosition.msg` – `Int8 Xr`, `Int8 Yr`
  - `RobotPosition.msg` – `Int8 X`, `Int8 Y`, `Float8 theta`
  - `Velocities.msg` – `Float32 Forward_Velocity`, `Float32 Angular_Velocity`
- **Control Logic:**  
  - Angular velocity: `w = e * Kp`  
  - Forward velocity: constant `V` decreasing as the robot approaches the target  
  - Stops when within 20 cm of the target

---

## Features

- Real-time publishing of robot and target positions
- Controller calculates velocities continuously
- Adjustable camera publishing frequency and message queue size:
  - Example: `rosrun two_wheeled_robot Camera 50 100` → 50 Hz, 100 max messages
- Feedback displayed via UI node for monitoring
- Fully implemented in **C++ (roscpp)** for Robot and Camera nodes; other nodes as desired

---

## ROS Workspace Structure

