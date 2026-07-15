# Task 3: IoT Prototype - Temperature & Humidity Monitoring

This prototype monitors ambient temperature and humidity using a DHT11 sensor and displays the readings on a 16x2 character LCD screen connected via I2C.

## Hardware Components and Connections

### 1. DHT11 Sensor
- **VCC** Pin -> Arduino **5V**
- **GND** Pin -> Arduino **GND**
- **Data** Pin -> Arduino Digital Pin **2**
- *Note: A 10kΩ pull-up resistor is placed between the Data pin and VCC to stabilize the data signal (standard DHT11 circuit).*

### 2. 16x2 LCD Screen with I2C Backpack (PCF8574)
- **VCC** Pin -> Arduino **5V**
- **GND** Pin -> Arduino **GND**
- **SDA** (Serial Data) Pin -> Arduino Analog Pin **A4** (or dedicated SDA pin)
- **SCL** (Serial Clock) Pin -> Arduino Analog Pin **A5** (or dedicated SCL pin)

## Logic & Flow
- The DHT library handles the timing-sensitive digital communication protocol with the DHT11 sensor.
- The `LiquidCrystal_I2C` library simplifies sending text to the LCD screen using the $I^2C$ communication protocol, which only requires 2 signal wires (SDA/SCL) instead of 6+ signal wires in standard parallel connection mode.
- Every 2 seconds, the `loop()` function triggers a sensor reading, converts the digital signals into temperature (Celsius) and humidity (Percentage), prints them to the Serial monitor, and displays them on the LCD screen.
- A `isnan()` sanity check is included to prevent printing corrupted or empty data if the sensor becomes disconnected.
