#include <RH_ASK.h>
#include <SPI.h>

RH_ASK driver;

void setup() {
  Serial.begin(9600); // Debugging only
  if (!driver.init()) {
    Serial.println("init failed");
  }
}

void loop() {
  const char *msg = "Welcome to IoT Laboratory";
  driver.send((uint8_t *)msg, strlen(msg));
  driver.waitPacketSent();
  Serial.println("Sender: Sending Data....");
  delay(1000);
}