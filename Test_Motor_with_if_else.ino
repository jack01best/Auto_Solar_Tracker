
/*test motor with if...else*/

int pin1=3;

/*Abnout input*/
int inputserial = A0;
float readvalue = 0;
float voltage = 0;



void setup()
{
  pinMode(pin1,OUTPUT);
  Serial.begin(9600);
  
}

void loop()
{
  
  readvalue=analogRead(inputserial);
  voltage=(readvalue+1)*5/1024;
  Serial.print("The voltage is:");
  Serial.println(voltage);
  
  
  if(voltage<1)
  {
    analogWrite(pin1,255);
  }
  if(voltage>=1)
  {
    digitalWrite(pin1,LOW);
  }
}
