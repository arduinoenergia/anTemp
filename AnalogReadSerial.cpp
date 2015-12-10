/*
  AnalogReadSerial
  Reads an analog input on pin A3, prints the result to the serial monitor.
  Attach the center pin of a potentiometer to pin A3, and the outside pins to ~3V and ground.
  
  Hardware Required:
  * MSP-EXP430G2 LaunchPad
  * 10-kilohm Potentiometer
  * hook-up wire

  This example code is in the public domain.
*/

#include "Energia.h"

#include <Servo.h>

void setup();
void loop();


Servo myservo;  // create servo object to control a servo
                // a maximum of eight servo objects can be created

int pos = 0;    // variable to store the servo position

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(115200); // msp430g2231 must use 4800
  //myservo.attach(9);  // attaches the servo on pin 9 to the servo object

}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin A3:
  //int sensorValue = analogRead(A3);
  volatile float tDeg, m;
  unsigned int * memRead = (unsigned int *) 0x1a1a;
  unsigned int * memRead1 = (unsigned int *) 0x1a1c;
  volatile unsigned int val = *memRead;
  volatile unsigned int val1 = *memRead1;
  //int sensorValue = analogRead(TEMPSENSOR);
  int sensorValue = analogRead(VMIDDLE);
  m = (85.0-30.0)/(val1 - val);
  tDeg = m * sensorValue + (30 - m * val);
  // print out the value you read:
  Serial.println(tDeg);
  delay(1000); // delay in between reads for stability
//  for(pos = 0; pos < 180; pos += 1)  // goes from 0 degrees to 180 degrees
//    {                                  // in steps of 1 degree
//      myservo.write(pos);              // tell servo to go to position in variable 'pos'
//      delay(15);                       // waits 15ms for the servo to reach the position
//    }
//    for(pos = 180; pos>=1; pos-=1)     // goes from 180 degrees to 0 degrees
//    {
//      myservo.write(pos);              // tell servo to go to position in variable 'pos'
//      delay(15);                       // waits 15ms for the servo to reach the position
//    }
}


