# Arduino 4-Digit 7-Segment Clock

A 24-hour digital clock built on Arduino that uses a 4-digit seven-segment display and push buttons for starting and manually adjusting the time.

## Features

- 24-hour timekeeping with automatic rollover from 23:59 to 00:00
- Manual hour and minute adjustment using push buttons
- Two-button activation to start the clock
- Multiplexed four-digit seven-segment display
- Millis-based timing for clock operation
- Internal pull-up configuration for button inputs

## Components

- Arduino Uno or Nano
- 4-digit seven-segment display
- 2x Push buttons
- Resistors
- Breadboard and jumper wires

## Pin Connections

| **Function** | **Arduino Pins** |
| --- | --- |
| 7-Segment Display (Segments a to g) | Pins 1 to 7 |
| Decimal Point (dp) | Pin 8 |
| Digit Select (Digit 1 to Digit 4) | Pins 12, 11, 10, 9 |
| Hour Adjustment Button | Pin 13 |
| Minute Adjustment Button | Pin 0 |

## Setup

1. Wire the hardware according to the pin connection table.
2. Open the `experiment3.ino` sketch in the Arduino IDE.
3. Select your board model and port under Tools.
4. Click Upload.
5. Press both buttons to start the clock.
6. Use the hour and minute buttons to adjust the time.

## Video Documentation

- [Project Demonstration and Testing Videos](https://drive.google.com/drive/folders/149qbVmrZvLpSra0fcZM-qeDlKP8Yd-61?usp=sharing)
