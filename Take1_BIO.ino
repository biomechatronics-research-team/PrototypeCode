/////////////////////////////////////////////////////////////
///////////////// INPUT/OUTPUT VARIABLES ////////////////////
/////////////////////////////////////////////////////////////
int CLK = 9;
int DT = 8;
//int RedLed = 5;
//int GreenLed = 6;

/////////////////////////////////////////////////////////////
/////////////////////// VARIABLES ///////////////////////////
/////////////////////////////////////////////////////////////
int State;
int LastState;
int RotPos = 0;
//boolean Clockwise;



void setup() {
  Serial.begin(9600);
  pinMode(CLK, INPUT);
  pinMode(DT, INPUT);
  //pinMode(RedLed, OUTPUT);
  //pinMode(GreenLed, OUTPUT);

  LastState = digitalRead(CLK);
}



void loop() {
  State = digitalRead(CLK);
  if(State != LastState) {
    if(digitalRead(DT) != State){
      RotPos = RotPos - 9;
    }
    else {
      RotPos = RotPos + 9;
    }
    //Serial.print("Position: ");
    Serial.println(RotPos);
  }
  LastState = State;
}
