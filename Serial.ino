/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial


#include <SoftwareSerial.h>
SoftwareSerial SwSerial(6, 7); // RX, TX
#include <Servo.h>
#include <BlynkSimpleSerialBLE.h>
#include <SoftwareSerial.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "6a654ee7998e491ea6853837ca6a0ce8";
Servo myservo; 
int pos = 0; 
int count=0;
String aaa;


SoftwareSerial SerialBLE(6, 7); // RX, TX

void setup()
{
      myservo.attach(9);
  // Debug console
  Serial.begin(9600);

  SerialBLE.begin(9600);
  Blynk.begin(SerialBLE, auth);

  Serial.println("Waiting for connections...");
}

void loop()
{
  
  if (SerialBLE.available()) {
   
    aaa=SerialBLE.read();
    Serial.println(aaa);
    
    if (aaa.endsWith("49"))
{
 Serial.println("gfdhghgf");
   for (pos = 15; pos <= 65; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
        // waits 15ms for the servo to reach the position
  }
}
   else if (aaa.endsWith("48"))
      {
        for (pos =65; pos >=15 ; pos -= 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);  
    // tell servo to go to position in variable 'pos'
      
    // waits 15ms for the servo to reach the position
      }
      }
  }
  // You can inject your own code or combine it with other sketches.
  // Check other examples on how to communicate with Blynk. Remember
  // to avoid delay() function!

else{}

}
