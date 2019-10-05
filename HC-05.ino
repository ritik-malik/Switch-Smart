#include <SoftwareSerial.h>// import the serial library
#include <Servo.h>

Servo myservo; 

int pos = 0; 
int count=0;
String aaa;

SoftwareSerial Genotronex(6, 7); // RX, TX

void setup() {
    myservo.attach(9);
  Genotronex.begin(9600);
  Serial.begin(9600);

}

void loop() {

  if (Genotronex.available()) {
   
    aaa=Genotronex.read();
    Serial.println(aaa);
    
    if (aaa.endsWith("49"))
{
   for (pos = 15; pos <= 65; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
                           // waits 15ms for the servo to reach the position
  }
}
    if (aaa.endsWith("48"))
      {
        for (pos =65; pos >=15 ; pos -= 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
                           // waits 15ms for the servo to reach the position
      }
    
  }
}
}
