#include <LiquidCrystal.h> 
int Contrast=100;
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
  delay(1000);
  reading = analogRead(knee);
  volts = reading * 0.0049; // this is not really necessary
  //angle given by linear regression:  
  angle = volts* 52.8759 + 21.1903;
  //add conversion operation from volts to degrees
  if(Serial.availableForWrite()){
    Serial.print(angle-30,1);
    Serial.print("\n");
    
  }
 }
