/*
Traffic lights control systems
by: 
Baston Hullet Longwe
Rage Dafter
Debbie Silungwe
Charity Kumpama
Kennedy Linzie
amin kapichi
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

const int buttonPin = 2;     // the number of the pushbutton pin
int buttonState = 0;         // variable for reading the pushbutton status





unsigned long previousMillis = 0;        // will store last time LED was updated

// constants won't change :
const long interval = 5000;           // interval at which to blink (milliseconds)
const long interval2 =7000 ;
const long interval3 =12000 ;
const long interval4 =14000 ;



void setup() {
  // initialize digital pin 13 as an output.
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(8, OUTPUT);

   pinMode(buttonPin, INPUT);

   myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

// the loop function runs over and over again forever
void loop() {
   buttonState = digitalRead(buttonPin);
  
 unsigned long currentMillis = millis();
 

if(buttonState == HIGH  )
{
  
  carcros_pedstop();
 delay(2000);
   carreadytostop_pedstop();
    gateClose();
     delay(2000); 
     Carstop_ped_cros();
   delay(4000);
  
  

  }
  else{
 
  if (currentMillis - previousMillis >= interval4) {
    // save the last time you blinked the LED
previousMillis = currentMillis;



}

  if (currentMillis - previousMillis >= 0 && currentMillis - previousMillis < interval ) {
    // save the last time you blinked the LED


Carstop_ped_cros();
Serial.println("1");

}

  if (currentMillis - previousMillis >= 5000 && currentMillis - previousMillis < interval2) {
    // save the last time you blinked the LED


carready_ped_cros();
gateOpen();

}


  if (currentMillis - previousMillis >= 7000 && currentMillis - previousMillis < interval3) {
    // save the last time you blinked the LED


carcros_pedstop();

}

 if (currentMillis - previousMillis >= 12000 && currentMillis - previousMillis < interval4) {
    // save the last time you blinked the LED


 carreadytostop_pedstop();
   gateClose();

}

}
}

void gateOpen()
{
  for (pos = 0; pos <= 90; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(22.22);                       // waits 15ms for the servo to reach the position
  }  
  
}

void gateClose()
{
   for (pos = 90; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(22.22);                       // waits 15ms for the servo to reach the position
  } 
  
}


  void Carstop_ped_cros()
  {
    
  digitalWrite(13, HIGH);   // Car stop
  digitalWrite(12, LOW);    
  digitalWrite(11, LOW);    
  digitalWrite(10, LOW);
  digitalWrite(8, HIGH);    // Pedestrians cross
 
  }

  void carready_ped_cros()
  {
  digitalWrite(13, LOW);    
  digitalWrite(12, HIGH);   // Car get ready to cross
  digitalWrite(11, LOW);  
  digitalWrite(10, LOW);
  digitalWrite(8,HIGH);    //Pedestrians cross
  
  }

  void carcros_pedstop()
  {
  digitalWrite(13, LOW);   
  digitalWrite(12, LOW);    
  digitalWrite(11, HIGH);   // Car cross
  digitalWrite(10, HIGH);   // Pedestrians stop
  digitalWrite(8, LOW); 
  
    
  }

  void carreadytostop_pedstop()
  {
  
  digitalWrite(13, LOW);    
  digitalWrite(12, HIGH);   // Car get ready to stop
  digitalWrite(11, LOW);  
  digitalWrite(10, HIGH);    // Pedestrians stop
  digitalWrite(8, LOW); 
 
  }
