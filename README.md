# Button Press Protection Circuit

This project implements a state machine using the Arduino framework for an ESP32 board that monitors a pushbutton. It tracks the button's state—OFF, ON, and PROTECTED—and measures how long the button remains pressed. After release, the system enters a PROTECTED state for 10 seconds, during which it displays the press duration and informs how long it will remain protected.

## Table of Contents
- [Features](#features)
- [Hardware Requirements](#hardware-requirements)
- [Software Requirements](#software-requirements)
- [How to Compile and Upload](#how-to-compile-and-upload)
- [Usage Examples](#usage-examples)

## Features

- **State Machine Logic:** Manages three states—OFF, ON, and PROTECTED to control the system flow.
- **Debouncing:** Ensures accurate button press detection by eliminating noise.
- **Duration Measurement:** Calculates and displays how long the button is pressed.
- **Protected State Messaging:** Informs the user of the remaining time in the PROTECTED state.
- **Low-Level Abstraction:** Designed for microcontroller-based applications using the Arduino framework.

## Hardware Requirements

- ESP32 DevKit or compatible Arduino board
- Pushbutton
- USB cable for programming and power supply

## Software Requirements

- Arduino IDE or PlatformIO
- ESP32 board support package (if using an ESP32 board)
- Basic knowledge of C/C++ programming

## How to Compile and Upload

1. Open the project in the Arduino IDE or PlatformIO.
2. Select the appropriate board (e.g., ESP32 DevKit).
3. Compile the project by clicking the **Verify/Compile** button.
4. Connect your board via USB.
5. Upload the program to the board.

## Usage Examples

- **Button Press:** When the button is pressed, the system transitions from OFF to ON, and the duration of the press is measured.
- **Protected State:** After releasing the button, the system enters the PROTECTED state, displaying the press duration and notifying the user with a message like:
  - *"Will remain in PROTECTED for 10 seconds"*
- **Automatic Transition:** Once the 10-second PROTECTED period elapses, the system automatically returns to the OFF state.