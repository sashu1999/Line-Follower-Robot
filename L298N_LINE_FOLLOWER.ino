int EA = 9; //ENA connected to digital pin 9
int EB = 3; //ENB connected to digital pin 3
int MA1 = 7; // MOTOR_A1 connected to digital pin 7
int MA2 = 6; // MOTOR_A2 connected to digital pin 6
int MB1 = 5; // MOTOR_B1 connected to digital pin 5
int MB2 = 4; / / MOTOR_B2 connected to digital pin 4

int RI = A0; // RIGHT sensor connected to analog pin A0
int LF = A1; // LEFT sensor connected to analog pin A1




void setup() {
  
pinMode(EA, OUTPUT); // initialize ENA pin as an output
pinMode(EB, OUTPUT); // initialize ENB pin as an output
pinMode(MA1, OUTPUT); // initialize MOTOR_A1 pin as an output
pinMode(MA2, OUTPUT); // initialize MOTOR_A2 pin as an output
pinMode(MB1, OUTPUT); // initialize MOTOR_B1 pin as an output
pinMode(MB2, OUTPUT); // initialize MOTOR_B2 pin as an output
pinMode(RI, INPUT); // initialize RIGHT pin as an input
pinMode(LF, INPUT); // initialize ENA pin as an input
}

void loop() {
  
if (analogRead(RI)<=35 && analogRead(LF)<=35)  //compare the both sensor to decide the direction
{
  
  analogWrite(EA, 100); // set right motors speed
  analogWrite(EB, 100); // set left motors speed
    //run right motors clockwise
  digitalWrite(MA1, LOW);
  digitalWrite(MA2, HIGH);
  //run left motors clockwise
  digitalWrite(MB1, HIGH);
  digitalWrite(MB2, LOW);
}
else if (analogRead(RI)<=35 && !analogRead(LF)<=35) //compare the both sensor to decide the direction
{
  
  analogWrite(EA, 255); //set right motors speed
  analogWrite(EB, 255); //set left motors speed
  //run right motors clockwise
  digitalWrite(MA1, LOW);
  digitalWrite(MA2, HIGH);
  //run left motors anti-clockwise
  digitalWrite(MB1, LOW);
  digitalWrite(MB2, HIGH);
}
else if (!analogRead(RI)<=35 && analogRead(LF)<=35) //compare the both sensor to decide the direction
{ 
  
  analogWrite(EA, 255); //set right motors speed
  analogWrite(EB, 255); //set left motors speed
  //run right motors anti-clockwise
  digitalWrite(MA1, HIGH);
  digitalWrite(MA2, LOW);
  //run left motors clockwise
  digitalWrite(MB1, HIGH);
  digitalWrite(MB2, LOW);
}
else if (!analogRead(RI)<=35 && !analogRead(LF)<=35) //compare the both sensor to decide the direction
{ 
  
  analogWrite(EA, 0); //set right motors speed
  analogWrite(EB, 0); //set left motors speed
  //stop right motors
  digitalWrite(MA1, LOW);
  digitalWrite(MA2, LOW);
  //stop left motors
  digitalWrite(MB1, LOW);
  digitalWrite(MB2, LOW);
  }
}
