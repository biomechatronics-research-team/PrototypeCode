#include <LiquidCrystal.h> 
int knee = A5;
int reading = 0;
float volts = 0.0;
float angle =  0.0;

void setup()
 {
  Serial.begin(9600);
 } 
void loop()
 { 
  delay(2);
  reading = analogRead(knee);
  volts = reading * 0.0049; // this is not really necessary
  //angle given by linear regression:  
  angle = volts* 52.8759 + 21.1903;
  //add conversion operation from volts to degrees
  if(Serial.availableForWrite()){
    Serial.println(angle-30,1);    
  }
 }
