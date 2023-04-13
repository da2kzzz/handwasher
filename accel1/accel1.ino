#include <Servo.h>
#include <Wire.h>
#include <Adafruit_MMA8451.h>
#include <Adafruit_Sensor.h>
const int motorPin = 9;

Adafruit_MMA8451 mma = Adafruit_MMA8451();
 
int Distance;//distance read from tof
int handle;

void setup() {
 pinMode(motorPin, OUTPUT); 
 
 Serial.begin(9600);

 Serial.println("Adafruit MMA8451 test!");
 if (! mma.begin()) {
    Serial.println("Couldnt start");
    //while (1);
  }
  Serial.println("MMA8451 found!");
  mma.setRange(MMA8451_RANGE_2_G);
}

void loop() {
  sensors_event_t event; 
  mma.getEvent(&event);

  /* Display the results (acceleration is measured in m/s^2) */
  Serial.print("X: \t"); Serial.print(event.acceleration.x); Serial.print("\t");
  Serial.print("Y: \t"); Serial.print(event.acceleration.y); Serial.print("\t");
  Serial.print("Z: \t"); Serial.print(event.acceleration.z); Serial.print("\t");
  Serial.println("m/s^2 ");
  
  /* Get the orientation of the sensor */
  uint8_t o = mma.getOrientation();
  
  switch (o) {
    case MMA8451_PL_PUF: 
      Serial.println("Portrait Up Front");
      handle = 0;
      break;
    case MMA8451_PL_PUB: 
      Serial.println("Portrait Up Back");
      handle = 1;
      break;    
    case MMA8451_PL_PDF: 
      Serial.println("Portrait Down Front");
      handle = 2;
      break;
    case MMA8451_PL_PDB: 
      Serial.println("Portrait Down Back");
      handle = 3;
      break;
    case MMA8451_PL_LRF: 
      Serial.println("Landscape Right Front");
      handle = 4;
      break;
    case MMA8451_PL_LRB: 
      Serial.println("Landscape Right Back");
      handle = 5;
      break;
    case MMA8451_PL_LLF: 
      Serial.println("Landscape Left Front");
      handle = 6;
      break;
    case MMA8451_PL_LLB: 
      Serial.println("Landscape Left Back");
      handle = 7;
      break;
    }
 
// potVal = analogRead(potPin); 
 //Serial.print("potVal: "); 
 //Serial.println(potVal);

// code for reading tof value here 
 
 if(handle!=0&&handle!=2){
 delay(2000); 
 digitalWrite(motorPin, HIGH);  
 }
 else{
  digitalWrite(motorPin, LOW);
 }

 delay(500);
}


int ifOpen(int dis){
  if(dis>=1000)//1000 should be the real value that detrmins whether the hadle is pulled or not
    return 1;
  else return 0;
}
