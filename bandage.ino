#include <Iremote.h>

int indicator = 12;       // indication
int RECV_PIN = 11;  //IR-receiver
int incomingByte = 0;

IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{
  pinMode(indicator, OUTPUT);
  Serial.begin(9600);
  irrecv.enableIRIn();
  digitalWrite(indicator, HIGH);
  delay(800);
  digitalWrite(indicator, LOW);
}

void loop() {
  if (irrecv.decode(&results))
    {
      if (results.value == 0x8304e8)
	{
	  Serial.print(1256);
	}
      else
	{
	  Serial.print(results.value);
	}
      delay(50);
      irrecv.resume();
    }

  if (Serial.available() > 0)
    {
      incomingByte = Serial.read();

      if (incomingByte == '1')
	{
	  digitalWrite(indicator, HIGH);
	}
      else if (incomingByte == '0')
	    {
	      digitalWrite(indicator, LOW);
	    }
      delay(20);
    }
  Serial.print(5);
  delay(80);
}
