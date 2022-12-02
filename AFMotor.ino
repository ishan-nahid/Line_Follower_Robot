#include <AFMotor.h>

#include <Stepper.h>

// All Code done by ISHAN AHMAD
//defining pins and variables
#define lefts A4 
#define rights A5 
int counter = 0;

//defining motors
AF_DCMotor motor1(4, MOTOR12_8KHZ); 
AF_DCMotor motor2(3, MOTOR12_8KHZ);
/*
AF_DCMotor motor1(3, MOTOR12_8KHZ); 
AF_DCMotor motor2(4, MOTOR12_8KHZ);
 */

void setup() {
  //setting the speed of motors
  motor1.setSpeed(400);
     
  motor2.setSpeed(440);
  //declaring pin types
  pinMode(lefts,INPUT);
  pinMode(rights,INPUT);
  //begin serial communication
  Serial.begin(9600);
  
}

void loop(){
  
  int leftIR = analogRead(lefts);
  int rightIR = analogRead(rights);  

  if(leftIR > 1000 && rightIR > 1000){ //stop
    motor1.run(RELEASE);
    motor2.run(RELEASE);    
  }
  else if(leftIR < 1000 && rightIR < 1000){ //start
    motor1.run(BACKWARD);
    motor2.run(FORWARD);    
  }
  else if(leftIR > 1000 && rightIR < 1000){ //turn left
    motor1.run(RELEASE);
    motor2.run(FORWARD);    
  }
  else if(leftIR < 1000 && rightIR > 1000){ //turn right
    motor2.run(RELEASE);
    motor1.run(BACKWARD);    
  }
  
}


