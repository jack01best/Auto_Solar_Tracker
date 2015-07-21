
/*test motor with if...else*/

int pin1=3;

/*Abnout input*/
int inputserial_0 = A0;
float readvalue_0 = 0;
float voltage_0 = 0;

int inputserial_1 = A1;
float readvalue_1 = 0;
float voltage_1 = 0;


void setup()
{
  pinMode(pin1,OUTPUT);
  Serial.begin(1200);
  
}

void loop()
{
  
  readvalue_0=analogRead(inputserial_0);
  voltage_0=(readvalue_0+1)*5/1024;
  Serial.print("The voltage_0 is:");
  Serial.println(voltage_0);
  
  readvalue_1=analogRead(inputserial_1);
  voltage_1=(readvalue_1+1)*5/1024;
  Serial.print("The voltage_1 is:");
  Serial.println(voltage_1);
  
  if( voltage_0<voltage_1/2-0.15 || voltage_0>voltage_1/2)
  {
    analogWrite(pin1,255);
  }
  if(voltage_0>=voltage_1/2-0.15 && voltage_0<=voltage_1/2)
  {
    digitalWrite(pin1,LOW);
  }
  delay(1000);
}
