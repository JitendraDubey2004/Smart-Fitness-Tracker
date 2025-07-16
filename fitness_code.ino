#include <Wire.h>
#include <SoftwareSerial.h>

#define BMA456_I2C_ADDRESS  0x19  // Default I2C address of BMA456

// Bluetooth HC-05 connection pins
#define RX 10  // Bluetooth HC-05 RX (Connect to TX of HC-05)
#define TX 11  // Bluetooth HC-05 TX (Connect to RX of HC-05)

SoftwareSerial BTSerial(RX, TX);

void setup() {
    Serial.begin(9600);
    BTSerial.begin(9600);  // Initialize Bluetooth module
    Wire.begin();  // Start I2C communication

    // Initialize BMA456
    if (!initializeBMA456()) {
        Serial.println("Error initializing BMA456 step sensor!");
        while (1);
    }

    Serial.println("Fitness Tracker Started");
}

// Function to initialize BMA456
bool initializeBMA456() {
    Wire.beginTransmission(BMA456_I2C_ADDRESS);
    if (Wire.endTransmission() != 0) {
        return false;  // Sensor not found
    }
    return true;
}

// Function to read step count from BMA456
int readStepCount() {
    Wire.beginTransmission(BMA456_I2C_ADDRESS);
    Wire.write(0x1E);  // Register address for step count (check BMA456 datasheet)
    Wire.endTransmission(false);
    
    Wire.requestFrom(BMA456_I2C_ADDRESS, 2);
    if (Wire.available() < 2) return -1;

    uint16_t stepCount = Wire.read();
    stepCount |= (Wire.read() << 8);
    return stepCount;
}

void loop() {
    int steps = readStepCount();

    // Send data via Serial and Bluetooth
    Serial.print("Steps: "); Serial.println(steps);
    BTSerial.print("Steps: "); BTSerial.println(steps);

    delay(1000); // Update every second
}
