#include <IRemote.h>

int anticheat = 6;
int trigger = 17;
int trasmitter = 14;
int weapons;

void setup()
{
  pinMode(anticheat, OUTPUT);
  Serial.begin(9600);
  weapons = 7;
}

void loop()
{
  if (digitalRead(trigger) == HIGH && weapons >= 0) {
    digitalWrite(trasmitter, HIGH);
    --weapons;
    delay(50);
  } else {
    digitalWrite(trasmitter, LOW);
    delay(50);
  }
  digitalWrite(anticheat, HIGH);
}