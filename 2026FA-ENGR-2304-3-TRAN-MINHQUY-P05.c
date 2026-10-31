/*2026FA-ENGR-2304-3-TRAN-MINHQUY-P05*/
#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void setup() {
	lcd.begin(16, 2);
	lcd.print("Hello World!");
}

void loop() {
}
