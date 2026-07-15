# Task 3: IoT Prototype - Smart Home Automation System

This prototype simulates a motion-activated smart home entry and lighting system. It uses a PIR motion sensor to detect human presence, a servo motor representing an automated door lock mechanism, and an LED representing the home lighting circuit.

## Hardware Components and Connections

### 1. Power Supply
- A **9V Battery** functions as the primary external power source. It is connected to the positive (red) and negative (black) rails of the breadboard to power the high-current devices (the Servo motor and the PIR sensor).
- The Arduino Uno is grounded to this common rail (Arduino **GND** -> breadboard **GND**).

### 2. PIR Motion Sensor
- **VCC** -> Breadboard **9V Rail** (or stepped down if needed, but standard PIR handles wide range; in simulation it's connected to the power rail).
- **GND** -> Breadboard **GND Rail**.
- **Out** (Signal) -> Arduino Digital Pin **2**.

### 3. Servo Motor (Smart Door Lock)
- **VCC (Red)** -> Breadboard **9V Rail** (Powered externally to avoid noise/brownouts on the Arduino).
- **GND (Black)** -> Breadboard **GND Rail**.
- **PWM Signal (Orange/Yellow)** -> Arduino Digital Pin **9**.

### 4. LED / Relay (Home Lighting)
- **Anode (Positive)** -> Arduino Digital Pin **8** (via a 220Ω resistor).
- **Cathode (Negative)** -> Breadboard **GND Rail**.

## Working Logic
1. The PIR sensor monitors motion. When motion is detected, digital pin `2` reads `HIGH`.
2. The Arduino turns the home light (digital pin `8`) **ON**.
3. The Servo motor sweeps from `0°` (locked) to `90°` (unlocked/open) to simulate opening a door.
4. When motion stops, the light turns **OFF**, and the Servo motor sweeps back to `0°` to lock/close the door.
