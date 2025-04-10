# Azul

This repository provides a template C++ application for building Azul exercises.

# Steeplechase Program

## Overview
The **Steeplechase** program simulates the movement of a mascot named Azul across a board, jumping between steeples as he travels from the far left to the far right. The program uses state-driven logic to control Azul's movement, where different states are handled as he navigates obstacles and jumps up steeples.

## Features
- **State-driven movement**: The program utilizes a state machine to manage Azul's movement across the board.
- **Steeple jumping**: Azul moves up to jump steeples when he encounters them.
- **Automatic pathfinding**: The program automatically determines if Azul needs to move down or step forward based on obstacles.
- **Program logic**: Azul transitions through various states: **Stepping**, **Moving Down**, **Moving Up**, and **Checking**.

## Code Structure

### `steeplechase.cpp`
- **Main program**: This file handles the main game logic. It manages Azul's movement through the different states (`Stepping`, `MovingDown`, `MovingUp`, `Checking`, and `Stopping`).
- **State machine**: Uses a state machine to guide Azul's actions across the board, making decisions based on the current state.

### Function Breakdown:
- **`check()`**: Checks if Azul can move forward or if he needs to move up due to a steeple.
- **`stepForward()`**: Moves Azul forward until he reaches a steeple or an obstacle.
- **`moveUp()`**: Handles moving Azul up when he encounters a steeple.
- **`down()`**: Moves Azul down until he hits the border of the board, then either checks again or stops.
- **`turnRight()`**: Turns Azul right by turning him left three times.

### Global Constants and Types:
- **`AzulState`**: Enum representing different states of Azul (e.g., `Stepping`, `MovingDown`, `Checking`, `MovingUp`, `Stopping`).

## Program Flow
1. **Initial state**: Azul starts in the **Stepping** state.
2. **Stepping**: Azul moves forward until an obstacle is encountered.
3. **Checking**: Azul checks if he can move forward or needs to move up due to a steeple.
4. **Moving Up**: If there’s a steeple, Azul moves up and continues checking for movement.
5. **Moving Down**: Once Azul has cleared the steeple, he moves down to a safe position.
6. **Stopping**: The program ends when Azul reaches the bottom of the board.

## Installation

### Requirements
- **Azul library**: The program uses the `Azul` class, which should be part of the project environment.
- **C++ Compiler**: A C++ compiler such as `g++` or `clang++`.

### Compilation
1. Save all source files in your project directory.
2. Make sure you have the `Azul` class and necessary dependencies set up.
3. Compile the program using a C++ compiler:
   ```bash
   g++ -o steeplechase steeplechase.cpp

## Sample Output
When you run the program, Azul will begin traveling across the board, stepping forward until he encounters a steeple. He will then jump up, check if he can move forward, and continue his journey until reaching the far right of the board.

Example Flow:
Azul starts at the left side and begins stepping forward.

He encounters a steeple, moves up to jump it, and continues.

Azul reaches the end of the board or encounters the bottom and stops.

## License

The source code is dual licensed under Public Domain and MIT -- choose whichever you prefer.
