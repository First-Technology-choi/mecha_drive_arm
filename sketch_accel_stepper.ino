#include <AccelStepper.h>  
const int step_pin = 10;  
const int dir_pin  = 11;  
long motorPosition = 0;  

unsigned int step_m0 = 9;
unsigned int step_m1 = 8;
unsigned int step_m2 = 7;

AccelStepper stepper(AccelStepper::DRIVER, step_pin, dir_pin);   
void setup()   
{   
  Serial.begin(9600);  
  stepper_init();    
  stepper.setCurrentPosition(0);  
}   

void microstepping_setup()
{
  pinMode(step_m0,OUTPUT);
  pinMode(step_m1,OUTPUT);
  pinMode(step_m2,OUTPUT);

  digitalWrite(step_m0,HIGH);
  digitalWrite(step_m1,HIGH);
  digitalWrite(step_m2,HIGH);
}
  
void loop()   
{   

  stepper.moveTo(8000);  
  stepper.runToPosition();  
  motorPosition = stepper.currentPosition();  
  Serial.println(motorPosition);  
  stepper.stop();  
  delay(1000);  
  
  stepper.moveTo(0);  
  stepper.runToPosition();  
  motorPosition = stepper.currentPosition();  
  Serial.println(motorPosition);  
  delay(1000);  
}   
  
void stepper_init(){   
  stepper.setMaxSpeed(100);   
  stepper.setAcceleration(1500);   
}  
