// Wire Slave Sender
// Demonstrates use of the Wire library
// Sends data as an I2C/TWI slave device
// Refer to the "Wire Master Reader" example for use with this

#include <Wire.h>

void setup() {
  Wire.begin(8);                // Join I2C bus with address #8
  Wire.onRequest(requestEvent); // Register requestEvent as an event
}

void loop() {
  delay(100); // Wait for 100ms
}

// Function that executes whenever data is requested by the master
void requestEvent() {
  Wire.write("Hello"); // Respond with a message of 5 bytes
}