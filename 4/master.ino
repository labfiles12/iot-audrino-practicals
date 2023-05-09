// Wire Master Reader
// Demonstrates use of the Wire library
// Reads data from an I2C/TWI slave device
// Refer to the "Wire Slave Sender/Receiver" example for use with this
#include <Wire.h>

void setup() {
  Wire.begin();        // join i2c bus (address optional for master)
  Serial.begin(9600);  // start serial for output
  Wire.beginTransmission(8); // transmit to device #8
  Wire.write('H');      // sends "H" to slave
  Wire.endTransmission();    // stop transmitting
}

void loop() {
  Wire.requestFrom(8, 1);    // request 1 byte from slave device #8
  if (Wire.available()) {   // slave may send less than requested
    char c = Wire.read();   // receive a byte as character
    if(c == 'H') {
      Serial.println("Command Accepted, Master- LED ON");
      digitalWrite(13, HIGH);
    }
    else if(c == 'L') {
      Serial.println("Command Accepted LED OFF");
      digitalWrite(13, LOW);
    }
  }
  delay(500);
}