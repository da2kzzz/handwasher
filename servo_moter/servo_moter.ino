#include <Servo.h>

Servo myServo;

int const potPin = A0;
int potVal;


void setup() {
 Serial.begin(9600);
}

void loop() {
 display_val();
 if(isPush(potVal)){
  while(true){
      if(index==0){
          servo_set();
     }  
      display_val();
      if(!isPush(potVal)) {
        break;
      }
  }
}
 servo_move();
 delay(100);
}

int isPush(int val){ // return 1 if handle is pushed
  if(val!=0) return 1;
  else return 0;
}
 /*int isHold(){//return 1 if Has released the handle
  delay(500);
  int val = 0;
  val = analogRead(potPin);
  Serial.print("potVal: ");
  Serial.println(val);
  if(isPush(val)) {
    isHold();
  }
  else return 1;
}*/

void servo_set(){
  myServo.attach(9);
  myServo.write(0);  
}

void servo_move(){
  myServo.write(90);
  delay(1000);
  myServo.write(0);
  delay(1000);
  myServo.detach();  
}

void display_val(){
 potVal = analogRead(potPin);
 Serial.print("potVal: ");
 Serial.println(potVal);  
}
