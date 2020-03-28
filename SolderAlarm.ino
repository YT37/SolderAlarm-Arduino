#include "DHT.h"
#define DHTTYPE DHT11

const int DHTP = A1;
const int Buzzer = 4;
const int Button = 7;

int ButtonRead;
int Temp;

DHT dht(DHTP, DHTTYPE);

void setup()
{
  Serial.begin(9600);

  pinMode(Buzzer, OUTPUT);
  pinMode(Button, INPUT_PULLUP);

  dht.begin();
}
void loop()
{
  Temp = dht.readTemperature();
  Serial.println(Temp);

  ButtonRead = digitalRead(Button);
  if (Temp >= 34 && ButtonRead == HIGH)
  {
    digitalWrite(Buzzer, HIGH);
  }

  else if (Temp != 34 || Temp < 34 && ButtonRead == HIGH || ButtonRead == LOW)
  {
    digitalWrite(Buzzer, LOW);
  }

  else
  {
    digitalWrite(Buzzer, LOW);
  }

  delay(2000);
}
