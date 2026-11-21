Arduino Pressure Control and Countdown

## Program Description

This program uses Arduino to control a compressor based on pressure values entered by the user.

First, the user enters the desired pressure and current pressure through the Serial Monitor. The Arduino compares these two values.

- If the current pressure is lower than the desired pressure, the compressor turns ON.
- If the current pressure reaches or is higher than the desired pressure, the compressor turns OFF.
- After reaching the desired pressure, the countdown starts automatically from 15 to 0.

## Components

- Arduino
- Compressor
- Relay module
- 16x2 I2C LCD
- 4 LEDs
- Connecting wires

## Pin Connections


1. Compressor - pin  8 
2. LED 1      - pin  13
3. LED 2      - pin  9
4. LED 3      - pin  7
5. LED 4      - pin  5
6. LCD I2C    - A4 and A5

## How to Use

1. Connect Arduino to the computer.
2. Open Serial Monitor and set the baud rate to 9600.
3. Enter the desired pressure.
4. Enter the current pressure.
5. Arduino compares the two pressure values and controls the compressor.
6. When the target pressure is reached, the compressor turns OFF and the countdown starts.

## Notes

- The program accepts binary input, such as `1010`.
- It also accepts hexadecimal input, such as `0x0A`.
- The LCD displays the countdown in decimal numbers.
- The user must enter the pressure values manually through Serial Monitor.