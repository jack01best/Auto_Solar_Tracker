
/*Final program*/

/*analog input serial*/

//up and down photoresistors
int aloginput0=A0;
float readvalue0 = 0;
float voltage0 = 0;

//left and right photoresistors
int aloginput1=A1;
float readvalue1 = 0;
float voltage1 = 0;

//Power supply
int aloginput2=A2;
float readvalue2 = 0;
float voltage2 = 0;



/*output pin for Motor*/
int pin1=3;
int pin2=5;
int pin3=9;
int pin4=11;

void setup()
{
  pinMode(pin1,OUTPUT);
  pinMode(pin2,OUTPUT);
  pinMode(pin3,OUTPUT);
  pinMode(pin4,OUTPUT);
  Serial.begin(1200);
}

void loop()
{
  //up and down photoresistors
  readvalue0=analogRead(aloginput0);
  voltage0=(readvalue0+1)*5/1024;
  Serial.print("The voltage0 is:");
  Serial.println(voltage0);
  
  //left and right photoresistors
  readvalue1=analogRead(aloginput1);
  voltage1=(readvalue1+1)*5/1024;
  Serial.print("The voltage1 is:");
  Serial.println(voltage1);
  
  //Power supply
  readvalue2=analogRead(aloginput2);
  voltage2=(readvalue2+1)*5/1024;
  
  //up and down
  if( voltage0<voltage2/2-0.1)
  {
    analogWrite(pin1,255);
    digitalWrite(pin2,LOW);
  }
  
  if(voltage0>voltage2/2+0.2)
  {
    digitalWrite(pin1,LOW);
    analogWrite(pin2,255);
  }
  
  
  if(voltage0>=voltage2/2-0.1 && voltage0<=voltage2/2+0.2)
  {
    digitalWrite(pin1,LOW);
    digitalWrite(pin2,LOW);
  }
  
  
  
  //left and right
  
    if(voltage1<voltage2/2-0.2)
  {
    analogWrite(pin4,255);
    digitalWrite(pin3,LOW);
  }
  
  if(voltage1>voltage2/2+0.2)
  {
    digitalWrite(pin4,LOW);
    analogWrite(pin3,255);
  }
  
  
  if(voltage1>=voltage2/2-0.2 && voltage1<=voltage2/2+0.2)
  {
    digitalWrite(pin3,LOW);
    digitalWrite(pin4,LOW);
  }
  
  
  delay(2000);
  
}
