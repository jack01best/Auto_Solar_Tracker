/*test input current of one resistor on Arduino*/

int inputserial0 = A0;
int inputserial1 = A1;
int inputserial2 = A2;
int inputserial3 = A3;

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


void setup(){
  Serial.begin(1200);
}



void loop(){
  
  voltage0=calculate(inputserial0);
  Serial.print("The voltage0 is:");
  Serial.println(voltage0);
  
  voltage1=calculate(inputserial1);
  Serial.print("The voltage1 is:");
  Serial.println(voltage1);
  
  voltage2=calculate(inputserial2);
  Serial.print("The voltage2 is:");
  Serial.println(voltage2);
  
  voltage3=calculate(inputserial3);
  Serial.print("The voltage3 is:");
  Serial.println(voltage3);
  
  delay(2000);
}
