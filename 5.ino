#include <dht.h>
#include <LiquidCrystal.h>

#define dht_apin A0 // Analog Pin sensor is connected to
char ch;
int Contrast = 15;

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
dht DHT;

void setup() {
  Serial.begin(9600);
  delay(500); // Delay to let system stabilize
  Serial.println("DHT11 Humidity & Temperature Sensor\n\n");
  pinMode(13, OUTPUT);
  analogWrite(6, Contrast);

  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  delay(1000); // Wait before accessing the sensor
}

void loop() {
  // Start of Program
  DHT.read11(dht_apin);

  // Print on Serial Monitor
  Serial.print("Current humidity = ");
  Serial.print(DHT.humidity);
  Serial.print("%\t");
  Serial.print("Temperature = ");
  Serial.print(DHT.temperature);
  Serial.println("C ");

  lcd.setCursor(0, 0); // goto first column (column 0) and first line (Line 0)
  lcd.print("Temp C = "); // Print at cursor Location
  lcd.print(DHT.temperature);

  lcd.setCursor(0, 1); // goto first column (column 0) and second line (line 1)
  lcd.print("Hum % = "); // Print at cursor location
  lcd.print(DHT.humidity);

  delay(5000); // Wait 5 seconds before accessing sensor again. Fastest should be once every two seconds.
}