#include <AFMotor.h>

#include <Stepper.h>

   ////////////////////////////////////////////////////////
  //                LinoBot v1.0                        //             
 //               By Aarav Garg                        //
////////////////////////////////////////////////////////

//I have added the possibilities of testing
//The values of analogRead could be changed for trouble shooting

//including the libraries


//defining pins and variables
#define lefts A4 
#define rights A5 

//defining motors
AF_DCMotor motor1(4, MOTOR12_8KHZ); 
AF_DCMotor motor2(3, MOTOR12_8KHZ);
/*
AF_DCMotor motor1(3, MOTOR12_8KHZ); 
AF_DCMotor motor2(4, MOTOR12_8KHZ);
 */

void setup() {
  //setting the speed of motors
  motor1.setSpeed(200);
  motor2.setSpeed(200);
  //declaring pin types
  pinMode(lefts,INPUT);
  pinMode(rights,INPUT);
  //begin serial communication
  Serial.begin(9600);
  
}

void loop(){
  //printing values of the sensors to the serial monitor
  Serial.print("Left:");
  Serial.println(analogRead(lefts));
  Serial.print("Right:");
  Serial.println(analogRead(rights));

  int leftIR = analogRead(lefts);
  int rightIR = analogRead(rights);
  // delay(1000);

  if(leftIR > 50 && rightIR > 150){
    motor1.run(RELEASE);
    motor2.run(RELEASE);    
  }
  else if(leftIR < 50 && rightIR < 150){
    motor1.run(BACKWARD);
    motor2.run(FORWARD);    
  }
  else if(leftIR > 50 && rightIR < 150){
    motor1.run(RELEASE);
    motor2.run(FORWARD);    
  }
  else if(leftIR < 50 && rightIR > 150){
    motor2.run(RELEASE);
    motor1.run(FORWARD);    
  }
/*
  //line detected by both
  if(analogRead(lefts)<=400 && analogRead(rights)<=400){
    //stop
    motor1.run(RELEASE);
    motor2.run(RELEASE);
  }
  //line detected by left sensor
  else if(analogRead(lefts)<=400 && !analogRead(rights)<=400){
    //turn left
    motor1.run(RELEASE);
    motor2.run(FORWARD);
    
    // motor2.run(BACKWARD);
    // motor1.run(FORWARD);
    /*
    motor1.run(RELEASE);
    motor2.run(FORWARD);
     
  }
  //line detected by right sensor
  else if(!analogRead(lefts)<=400 && analogRead(rights)<=400){
    //turn right
    motor2.run(RELEASE);
    motor1.run(FORWARD);
    
    // motor2.run(FORWARD);
    // motor1.run(BACKWARD);
    /*
    motor1.run(FORWARD);
    motor2.run(RELEASE);
     
  }
  //line detected by none
  else if(!analogRead(lefts)<=400 && !analogRead(rights)<=400){
    // start
    motor1.run(BACKWARD);
    motor2.run(FORWARD);
    //stop
    /*
    motor1.run(FORWARD);
    motor2.run(FORWARD);
    /*
    motor1.run(BACKWARD);
    motor2.run(BACKWARD);
     
  }
  */
}


