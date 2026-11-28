Arduino Pressure Control and Countdown
Program Description
This program uses Arduino to control a compressor based on pressure values adjusted by two potentiometers.
First, the user turns two potentiometers to adjust the desired pressure and current pressure. The Arduino reads and compares these two values.
* If the current pressure is lower than the desired pressure, the compressor turns ON.
* If the current pressure reaches or is higher than the desired pressure, the compressor turns OFF.
* After reaching the desired pressure, the countdown starts automatically from 15 to 0.
* During the countdown, 4 LEDs display the binary value, and the LCD displays the countdown in decimal numbers.
Components
* Arduino
* Compressor
* Relay module
* 16x2 I2C LCD
* 4 LEDs
* 2 Potentiometers
* Connecting wires
Pin Connections
1. Compressor - pin 8
2. LED 1 - pin 13
3. LED 2 - pin 9
4. LED 3 - pin 7
5. LED 4 - pin 5
6. LCD I2C - A4 and A5
7. Target Pressure Potentiometer - Analog pin A0
8. Current Pressure Potentiometer - Analog pin A1
How to Use
1. Connect Arduino to the computer.
2. Turn the first potentiometer to adjust the desired pressure.
3. Turn the second potentiometer to adjust the current pressure.
4. Arduino reads and compares the two pressure values.
5. If the current pressure is lower than the desired pressure, the compressor turns ON.
6. If the target pressure is reached, the compressor turns OFF and the countdown starts.
7. The 4 LEDs display the binary countdown, while the LCD displays the decimal countdown.
Notes
* Two potentiometers are used to adjust the desired pressure and current pressure.
* The Arduino reads analog values from pins A0 and A1.
* The LCD displays the countdown in decimal numbers.
* The 4 LEDs display the countdown in binary.
* Each countdown number lasts for 1 second.
* The countdown runs from 15 to 0.

