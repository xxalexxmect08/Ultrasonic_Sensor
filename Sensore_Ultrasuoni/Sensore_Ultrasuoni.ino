#include <HCSR04.h>

const int elements_number = 10;
int store_values[elements_number];

int echoPin = 5;
int trigPin = 4;
UltraSonicDistanceSensor distanceSensor(trigPin, echoPin);

void setup() {
  Serial.begin(9600);
  Serial.println("time, distance");

}

void loop() {
  for (int i = 0; i<elements_number; i ++){
    int distanza = distanceSensor.measureDistanceCm();
    if (distanza == -1){
      Serial.println("OUT OF SCALE");
    }
    else{
      store_values[i] = distanza;
    }
    delay(20);
  }
 unsigned long media = 0;
 for (int i = 0; i< elements_number; i++){
  media += store_values[i];
 }
media = media / elements_number;
Serial.print(millis() / 1000);
Serial.print(", ");
Serial.println(media);
delay(10);
}
