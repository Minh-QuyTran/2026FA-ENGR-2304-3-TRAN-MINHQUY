/*2026FA - ENGR - 2304 - 3 - TRAN - MINHQUY - P10*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int compressorPin = 8;

String targetInput;
String currentInput;

int targetPressure;
int currentPressure;

LiquidCrystal_I2C lcd(0x27, 16, 2);

int ledspin[] = { 13,9,7,5 };
int count = 15;

void setup() {
    Serial.begin(9600);

    pinMode(compressorPin, OUTPUT);
    digitalWrite(compressorPin, LOW);

    for (int i = 0;i < 4;i++) {
        pinMode(ledspin[i], OUTPUT);
    }

    lcd.init();
    lcd.backlight();
    lcd.clear();

    Serial.println("Enter desired pressure:");
}

/*I used chatGPT to help me creat pressure code*/
void loop() {

    if (Serial.available() > 0) {

        targetInput = Serial.readStringUntil('\n');
        targetInput.trim();

        targetPressure = convertInput(targetInput);

        Serial.print("Target Pressure: ");
        Serial.println(targetPressure);

        Serial.println("Enter current pressure:");

        while (Serial.available() == 0) {
        }

        currentInput = Serial.readStringUntil('\n');
        currentInput.trim();

        currentPressure = convertInput(currentInput);

        Serial.print("Current Pressure: ");
        Serial.println(currentPressure);

        if (currentPressure >= targetPressure) {
            digitalWrite(compressorPin, LOW);
            Serial.println("Target pressure reached.");
            Serial.println("Compressor OFF");

            countdown();
        }
        else {
            digitalWrite(compressorPin, HIGH);
            Serial.println("Pressure is below target.");
            Serial.println("Compressor ON");
        }

        Serial.println("Enter desired pressure:");
    }
}

int convertInput(String input) {

    if (input.startsWith("0x") || input.startsWith("0X")) {
        return (int)strtol(input.c_str(), NULL, 16);
    }
    else {
        return (int)strtol(input.c_str(), NULL, 2);
    }
}

void countdown() {

    count = 15;

    while (count >= 0) {

        for (int i = 0;i < 4;i++) {
            digitalWrite(ledspin[i], bitRead(count, i));
        }

        lcd.setCursor(0, 0);
        lcd.print("Decimal: ");
        lcd.print(count);
        lcd.print("   ");

        delay(1000);

        count = count - 1;
    }

    for (int i = 0;i < 4;i++) {
        digitalWrite(ledspin[i], LOW);
    }

    lcd.clear();

    Serial.println("Countdown completed.");
}
