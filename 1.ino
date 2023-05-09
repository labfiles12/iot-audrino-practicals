String name;
int age;
float height;

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println("\nEnter your Name:");
  while(Serial.available() == 0) {}
  name = Serial.readString();

  Serial.println("Sending name...");
  delay(10000);

  Serial.println("Enter your Age:");
  while(Serial.available() == 0) {}
  age = Serial.parseInt();

  Serial.println("Sending age...");
  delay(10000);

  Serial.println("Enter your Height Feet.inch :");
  while(Serial.available() == 0) {}
  height = Serial.parseFloat();

  Serial.println("Sending height...");
  delay(5000);

  display();
}

void display() {
  Serial.print("Hello ");
  Serial.print(name);
  Serial.print(", you are ");
  Serial.print(age);
  Serial.print(" years old and ");
  Serial.print("you are ");
  Serial.print(height);
  Serial.println(" tall");
}