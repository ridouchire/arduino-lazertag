#include <Iremote.h>

int indicator = 12;       // indication
int incomingByte = 0;

void setup()
{
  pinMode(indicator, OUTPUT);
  Serial.begin(9600);
  digitalWrite(indicator, HIGH);
  delay(800);
  digitalWrite(indicator, LOW);
}

void loop() {
  if (Serial.available() > 0) {
    incomingByte = Serial.read();
    if (incomingByte == '1') {
      digitalWrite(indicator, HIGH);
    } else if (incomingByte == '0') {
      digitalWrite(indicator, LOW);
    }
    delay(20);
  }
  Serial.print(5);
  delay(80);
}