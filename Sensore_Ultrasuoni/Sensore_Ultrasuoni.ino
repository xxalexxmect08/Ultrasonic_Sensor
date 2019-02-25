#include <HCSR04.h>

int echoPin = 5;
int trigPin = 4;
UltraSonicDistanceSensor distanceSensor(trigPin, echoPin);

void setup() {
  Serial.begin(9600);

}

void loop() {
 Serial.println(distanceSensor.measureDistanceCm());
 delay(10);

}
