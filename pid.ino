#include<AutoPID.h>

#define output 5
#define input A0
#define sp A1
#define KP .31
#define KI .008
#define KD .0002

double sensor, setPoint, outVal;

AutoPID pid(&sensor, &setPoint, &outVal, 0, 255, KP, KI, KD);

void setup() {
  Serial.begin(9600);
  pinMode(output, OUTPUT);
  pid.setBangBang(1);
  pid.setTimeStep(1);
}

void loop() {
  sensor = analogRead(input);
  setPoint = analogRead(sp);
  pid.run();
  analogWrite(output, outVal);
}
