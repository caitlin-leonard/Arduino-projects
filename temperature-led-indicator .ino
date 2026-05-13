
const int sensorpin=A0;
const float baselinetemp=25.0;



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //opening a serial port
  for (int pinnumber=2; pinnumber<5; pinnumber++){
    pinMode(pinnumber,OUTPUT);
    digitalWrite(pinnumber,LOW);
  }



}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorval=analogRead(sensorpin);
  Serial.print(" sensor value:");
  Serial.print(sensorval);

  //convert the ADC reading into voltage
  float voltage =(sensorval/1024.0)*5.0;
  Serial.print(", volts:");
  Serial.print(voltage);
  Serial.print(", degrees C :");

  //convert the voltage to temp in deg c
  float temp=(voltage- .5)*100;
  Serial.println(temp);
  
  //very low temp
  if(temp<baselinetemp+2){
    digitalWrite(2,LOW);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
  }
  //low temp
  else if(temp>=baselinetemp+2 && temp<baselinetemp+4){
    digitalWrite(2,HIGH);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);

  }
  //medium temp
  else if(temp>=baselinetemp+4 && temp<baselinetemp+6){
    digitalWrite(2,HIGH);
    digitalWrite(3,HIGH);
    digitalWrite(4,LOW);
  }
  //high temp
  else if(temp>=baselinetemp+6){
    digitalWrite(2,HIGH);
    digitalWrite(3,HIGH);
    digitalWrite(4,HIGH);
  }

delay(1);

}
