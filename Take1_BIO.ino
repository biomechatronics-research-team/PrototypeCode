/////////////////////////////////////////////////////////////
///////////////// INPUT/OUTPUT VARIABLES ////////////////////
/////////////////////////////////////////////////////////////
int CLK = 3;          //Initialize CLK pin on the encoder
int DT = 2;           //Initialize DT pin on the encoder
/////////////////////////////////////////////////////////////
/////////////////////// VARIABLES ///////////////////////////
/////////////////////////////////////////////////////////////
int State;            //Current angle of the encoder's CLK
int LastState;        //Previous angle of the encoder's CLK
int RotPos = 90;      //Starting position of the encoder (reference)

/* This code holds the instructions to be followed by the Arduino 
 * and the encoder to obtain data from the subject's leg at two points:
 * the knee and the hip. It registers angle movements and shows them in
 * the Serial Monitor every 1 millisecond.
 * @author Ernesto A. Sanchez Lopez
  */

void setup() {
  Serial.begin(9600);
  pinMode(CLK, INPUT);
  pinMode(DT, INPUT);

  // Read encoder position before loop begins
  LastState = digitalRead(CLK);
}

void loop() {
  // Read current encoder position
  State = digitalRead(CLK);
  if(State != LastState) {          // When State and LastState are not equal, a change in position has occured 
    if(digitalRead(DT) != State){   // If DT pin does not equal State, the encoder has been moved counter clockwise
      RotPos = RotPos - 9;        
    }
    else {                          // If DT pin equals State, the encoder has been moved clockwise
      RotPos = RotPos + 9;
    }
  }
  LastState = State;
  // Print current position every 1 millisecond
  Serial.println(RotPos);
  delay(1);
}
