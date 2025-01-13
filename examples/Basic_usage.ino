#include <A02YYUW.h>

A02YYUW sensor(10, 11); // Tentukan pin RX dan TX

void setup() {
  Serial.begin(115200);
  sensor.begin(); // Inisialisasi sensor
  Serial.print("A02YYUW Test");
  Serial.print(" Please wait...");
  delay(1000);
}

void loop() {
  int distance = sensor.getDistance();
  if (distance != -1) {
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");
  } else {
    Serial.println("No valid data.");
  }
  delay(500);
}
