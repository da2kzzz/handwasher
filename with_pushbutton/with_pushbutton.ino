#include <Servo.h>

Servo myServo;

int const potPin = A0; 
int potVal; 
int Distance;//distance read from tof

void setup() {
 myServo.attach(9);
 myServo.write(0);
 Serial.begin(9600);
}

void loop() {
 potVal = analogRead(potPin); 
 Serial.print("potVal: "); 
 Serial.println(potVal);
 /*
 code for reading tof value here 
 */
 if(isPush(potVal)){ 
 myServo.write(90);
 delay(2000);
 myServo.write(0);
 }
 /*
 if(isOpen(Distance)){ // use this code when we have tof 
 myServo.write(90);
 delay(2000);
 myServo.write(0);
 }
 */
 delay(2000);
}

int isPush(int val){
  if(val!=0) return 1;
  else return 0;
}

int ifOpen(int dis){
  if(dis>=1000)//1000 should be the real value that detrmins whether the hadle is pulled or not
    return 1;
  else return 0;
}
