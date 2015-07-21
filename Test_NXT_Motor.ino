/*Lego Motor Test*/

int pinM1=3;
int pinM2=5;

void setup()
{
  pinMode(pinM1,OUTPUT);
  pinMode(pinM2,OUTPUT);
}

void loop()
{
  analogWrite(pinM1, 255);
  digitalWrite(pinM2,LOW);
  delay(1000);
  analogWrite(pinM2, 255);
  digitalWrite(pinM1,LOW);
  delay(1000);
  

}
