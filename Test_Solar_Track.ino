//Test Solar track

int leftPin=3;
int rightPin=5;
int upPin=9;
int downPin=11;


int leftRe = A0;
int rightRe = A1;
int upRe = A2;
int downRe = A3;


float voltage0=0;
float voltage1=0;
float voltage2=0;
float voltage3=0;


float calculate (int inputserial)
{
  float readvalue=0;
  float voltage=0;
  readvalue=analogRead(inputserial);
  voltage=(readvalue+1)*5/1024;
  return voltage;
}



void setup()
{
  pinMode(leftPin,OUTPUT);
  pinMode(rightPin,OUTPUT);
  pinMode(upPin,OUTPUT);
  pinMode(downPin,OUTPUT);
  Serial.begin(57600);
}

void loop()
{
  //calculate voltage
  voltage0=calculate(leftRe);
  Serial.print("The voltage0 is:");
  Serial.println(voltage0);
  
  voltage1=calculate(rightRe);
  Serial.print("The voltage1 is:");
  Serial.println(voltage1);
  
  voltage2=calculate(upRe);
  Serial.print("The voltage2 is:");
  Serial.println(voltage2);
  
  voltage3=calculate(downRe);
  Serial.print("The voltage3 is:");
  Serial.println(voltage3);
  
  //compare: left/right
  
  if(voltage0>=voltage1-0.5&&voltage0<=voltage1+0.5)
  {
    digitalWrite(leftPin,LOW);
    digitalWrite(rightPin,LOW);
  }
  
  if(voltage0<voltage1-0.5)
  {
    analogWrite(rightPin, 255);
    digitalWrite(leftPin,LOW);
  }
  
  if(voltage0>voltage1+0.5)
  {
    analogWrite(leftPin,255);
    digitalWrite(rightPin,LOW);
  }
  
  //compare: up/down
  
  if(voltage2>=voltage3-0.5&&voltage2<=voltage3+0.5)
  {
    digitalWrite(upPin,LOW);
    digitalWrite(downPin,LOW);    
  }
  
  if(voltage2<voltage3-0.5)
  {
    analogWrite(downPin,255);
    //digitalWrite(downPin,HIGH);
    digitalWrite(upPin,LOW);
  }
  
  if(voltage2>voltage3+0.5)
  {
    analogWrite(upPin,255);
    digitalWrite(downPin,LOW);
  }
  Serial.print("\n");
  //delay(2000);
}






