
#include <Servo.h> //include the servo library

int pos=0; //declare initial position of the servo
int servoPin = 10; //declare pin for the servo
int servoDelay =15; //delay to allow the servo to reach position;
int a; //declare variable used to increment the servo angle



Servo myServo; // create a servo object called myServo

void setup() {
  Serial.begin(9600); //start serial port
  myServo.attach(servoPin); //declare to which pin is the servo connected
  myServo.write(pos);
}

void loop() {
  if(Serial.available()>0){ //wait until information is received from the serial port
  a = Serial.read()-48;
  delay(1);
  if (a==5){pos=pos+a;}; //increment position if attention level is above threshold
  if (a==2){pos=pos;}; //stop incrementing position if attention level lower than threshold
  //the value 5 is the increment value and the value 2 is just set as a flag
  if (pos>180){pos=180;};
  //this is the max angle (in the case of a 270 degrees servo it's 270 degrees)
  if (pos<0){pos =0;};
  if (pos>90){pos=0;};
  //this is the position, at which the servo resets to 0 corresponding to the position, at which the spoon breaks
  Serial.println(pos);
  myServo.write(pos); //write the position into the servo
  delay(servoDelay); //give time to the servo to reach the position
  };
}

