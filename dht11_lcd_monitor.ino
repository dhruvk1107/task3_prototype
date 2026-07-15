/*
  Task 3: IoT Prototype - Temperature & Humidity Monitoring System
  Interfacing a DHT11 temperature/humidity sensor and a 16x2 I2C LCD screen with Arduino Uno.
*/

#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define DHTPIN 2          // DHT11 connected to Digital Pin 2
#define DHTTYPE DHT11     // Specifying DHT 11 type

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2); // Set the LCD address to 0x27 for a 16 chars and 2 line display

void setup() {
    Serial.begin(9600);
    dht.begin();
    
    lcd.init();         // Initialize the LCD
    lcd.backlight();    // Turn on the LCD backlight
    lcd.setCursor(0, 0);
    lcd.print("IoT Weather Stn");
    lcd.setCursor(0, 1);
    lcd.print("Initializing...");
    delay(2000);
    lcd.clear();
}

void loop() {
    // Reading temperature or humidity takes about 250 milliseconds
    float h = dht.readHumidity();
    float t = dht.readTemperature(); // Read temperature in Celsius

    // Check if any reads failed and exit early (to try again)
    if (isnan(h) || isnan(t)) {
        Serial.println("Failed to read from DHT sensor!");
        lcd.setCursor(0, 0);
        lcd.print("Sensor Error!   ");
        return;
    }

    // Print to Serial Monitor
    Serial.print("Humidity: ");
    Serial.print(h);
    Serial.print(" %  |  ");
    Serial.print("Temp: ");
    Serial.print(t);
    Serial.println(" *C");

    // Display on LCD
    lcd.setCursor(0, 0);
    lcd.print("Temp: ");
    lcd.print(t);
    lcd.print(" C     ");

    lcd.setCursor(0, 1);
    lcd.print("Humidity: ");
    lcd.print((int)h);
    lcd.print(" %   ");

    delay(2000); // Update display every 2 seconds
}
