/*
  Task 3: IoT Prototype - Smart Home Automation System
  PIR motion detection triggers a servo motor (automated door) and turns on home lights.
  Powered via external 9V battery power supply to breadboard.
*/

#include <Servo.h>

const int PIR_PIN = 2;     // PIR sensor signal pin
const int LED_PIN = 8;     // Home light LED / Relay signal pin
const int SERVO_PIN = 9;   // Servo motor control pin

Servo doorServo;
int pirState = LOW;        // Start with no motion detected
int val = 0;               // Variable for reading the pin status

void setup() {
    pinMode(PIR_PIN, INPUT);     // PIR as input
    pinMode(LED_PIN, OUTPUT);    // LED as output
    doorServo.attach(SERVO_PIN); // Attach servo
    
    // Initial state: Door closed (0 degrees), Light off
    doorServo.write(0);
    digitalWrite(LED_PIN, LOW);
    
    Serial.begin(9600);
    Serial.println("Smart Home Automation System Initialized.");
}

void loop() {
    val = digitalRead(PIR_PIN); // Read PIR sensor input
    
    if (val == HIGH) { // If motion is detected
        digitalWrite(LED_PIN, HIGH); // Turn light ON
        
        if (pirState == LOW) {
            Serial.println("Motion detected! Turning lights ON and opening door...");
            
            // Sweep servo from 0 to 90 degrees to open door
            for (int pos = 0; pos <= 90; pos += 1) {
                doorServo.write(pos);
                delay(15);
            }
            pirState = HIGH;
        }
    } else {
        digitalWrite(LED_PIN, LOW); // Turn light OFF
        
        if (pirState == HIGH) {
            Serial.println("Motion ended. Turning lights OFF and closing door...");
            
            // Sweep servo from 90 to 0 degrees to close door
            for (int pos = 90; pos >= 0; pos -= 1) {
                doorServo.write(pos);
                delay(15);
            }
            pirState = LOW;
        }
    }
    delay(500); // Poll every 500ms
}
