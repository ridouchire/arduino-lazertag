#include <IRemote.h>

int anticheat = 6;
int trigger = 17;
int trasmitter = 14;

void setup()
{
  pinMode(anticheat, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  if (digitalRead(trigger) == HIGH) {
    digitalWrite(trasmitter, HIGH);
    delay(50);
  } else {
    digitalWrite(trasmitter, LOW);
    delay(50);
  }
  digitalWrite(anticheat, HIGH);
}