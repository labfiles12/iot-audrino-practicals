// Wire Slave Reader
// Demonstrates use of the Wire library
// Reads data from an I2C/TWI master device

#include <Wire.h>

void setup() {
  Wire.begin(5); // join I2C bus with address #5
  Serial.begin(9600); // start serial for output
  pinMode(13, OUTPUT); // initialize LED pin
}

void loop() {
  Wire.requestFrom(8, 1); // request 1 byte from master device with address #8

  while (Wire.available()) {
    // slave may send less than requested
    char c = Wire.read(); // receive a byte as character
    
    if (c == 'H') {
      digitalWrite(13, HIGH); // turn on LED
      Serial.println("Command Accepted, Slave Reader LED ON");
    } else if (c == 'L') {
      digitalWrite(13, LOW); // turn off LED
      Serial.println("Command Accepted, Slave Reader LED OFF");
    }
  }

  delay(100);
}