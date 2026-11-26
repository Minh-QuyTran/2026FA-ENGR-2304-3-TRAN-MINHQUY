/*2026FA-ENGR-2304-3-TRAN-MINHQUY-P11*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// LCD I2C
LiquidCrystal_I2C lcd(0x27, 16, 2);

// LED pins
int ledspin[] = { 5, 7, 9, 13 };

// Potentiometer pins
int targetPin = A0;
int currentPin = A1;

// Pressure variables
int targetPressure = 0;
int currentPressure = 0;

// Countdown status
bool countdownStarted = false;

void setup() {

    // Set LED pins as OUTPUT
    for (int i = 0; i < 4; i++) {
        pinMode(ledspin[i], OUTPUT);
    }

    lcd.init();
    lcd.backlight();
    lcd.clear();
}

void loop() {

    // Read potentiometers
    targetPressure = map(analogRead(targetPin), 0, 1023, 0, 100);
    currentPressure = map(analogRead(currentPin), 0, 1023, 0, 100);

    // Display pressure values
    lcd.setCursor(0, 0);
    lcd.print("T:");
    lcd.print(targetPressure);
    lcd.print(" C:");
    lcd.print(currentPressure);
    lcd.print("   ");

    // Start countdown when current reaches target
    if (!countdownStarted &&
        targetPressure > 0 &&
        currentPressure >= targetPressure) {

        countdownStarted = true;

        // Countdown from 15 to 1
        for (int count = 15; count > 0; count--) {

            // Display countdown
            lcd.setCursor(0, 1);
            lcd.print("Countdown: ");
            lcd.print(count);
            lcd.print("   ");

            // Display binary using LEDs
            for (int i = 0; i < 4; i++) {
                digitalWrite(ledspin[i], bitRead(count, i));
            }

            delay(1000);
        }

        // Turn off all LEDs
        for (int i = 0; i < 4; i++) {
            digitalWrite(ledspin[i], LOW);
        }

        // Display completion
        lcd.setCursor(0, 1);
        lcd.print("COMPLETED!      ");
    }
}
