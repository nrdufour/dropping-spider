
#include <AFMotor.h>

// Connect a stepper motor with 48 steps per revolution (7.5 degree)
// to motor port #2 (M3 and M4)
AF_Stepper motor(48, 2);

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Halloween Spider STARTING!!");

  Serial.println("Setting speed to 250 RPM");
  motor.setSpeed(500);
}

void move_spider() {
  Serial.println("MOVE SPIDER! /\\o/\\");
  motor.step(1000, FORWARD, DOUBLE);
  motor.step(500, BACKWARD, DOUBLE);
  motor.step(500, FORWARD, DOUBLE);
  motor.step(1000, BACKWARD, DOUBLE);
}

int sense_sonar() {
  Serial.println("Sonar sensing...");
  
  int distsensor, i;
  distsensor = 0;
  for (i=0; i<8; i++) {
    distsensor += analogRead(0);
    delay(50);
  }
  
  distsensor /= 8;
  
  return distsensor;
}

void loop() {
   int distsensor = sense_sonar();
   
   Serial.print("Sonar is: ");
   Serial.println(distsensor);
   if(distsensor < 200) {
     Serial.println("I found a prey! Time to move!!");
     move_spider();
   }
   
   delay(100);
}
