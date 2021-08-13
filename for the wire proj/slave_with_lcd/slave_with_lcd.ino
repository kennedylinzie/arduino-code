#include <Wire.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);


int LED = 13;
int threshold = 15;
const int ledPingreen =  52; //GREEN
const int ledPinblue = 50 ; //BLUE
const int ledPingrey =  48; //GREY
const int ledPinred =  46; //RED


int brightness = 0;    // how bright the LED is
int fadeAmount = 10;    // how many points to fade the LED by
char c;
int x;
int k;
String moose;
char  letter=  1;
 
unsigned long previousMillis = 0;        // will store last time LED was updated

// constants won't change :
const long interval = 1000;
boolean smile;


void setup() {
  Wire.begin(8);                // join i2c bus with address #8
  Wire.onReceive(receiveEvent); // register event
  Serial.begin(9600);           // start serial for output
  lcd.begin(16, 2);
  pinMode(ledPingreen, OUTPUT);
  pinMode(ledPinblue, OUTPUT);
  pinMode(ledPingrey, OUTPUT);
  pinMode(ledPinred, OUTPUT);
  smile = false;

}

void loop() {
  


  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;
   
    Serial.print(c); // print the character
   
  
    if (smile == true) {

      // fade in from min to max in increments of 5 points:
      for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) {
        // sets the value (range from 0 to 255):
        analogWrite(ledPinred, fadeValue);
        // wait for 30 milliseconds to see the dimming effect
        delay(30);
      }

      // fade out from max to min in increments of 5 points:
      for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 5) {
        // sets the value (range from 0 to 255):
        analogWrite(ledPinred, fadeValue);
        // wait for 30 milliseconds to see the dimming effect
        delay(30);
      }
    }

  }





}

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int howMany) {
  while (1 < Wire.available()) { // loop through all but the last
    smile = false;
   char c = Wire.read(); // receive byte as a character
    Serial.print(c); // print the character
   String moose = String(c);
      

  }

 
   // receive byte as an integer
  
 int  x = Wire.read();
      
     
 

  if (x <= 29 && x > 22) {
    digitalWrite(ledPingreen, HIGH); Serial.print("green   "); Serial.println(x);
    // Print a message to the LCD.
    lcd.setCursor(14, 0);
    lcd.println(x);

    lcd.setCursor(0, 0);
    lcd.print("Energy:  ");
     lcd.setCursor(0, 1);

 lcd.print("System running");
 



  } else {
    digitalWrite(ledPingreen, LOW ); 
  }

  
  if (x <= 22 && x > 15) {
    digitalWrite(ledPinblue, HIGH); Serial.print("blue   "); Serial.println(x);
       // Print a message to the LCD.
    lcd.setCursor(14, 0);
    lcd.println(x);

    lcd.setCursor(0, 0);
    lcd.print("Energy:  ");
     lcd.setCursor(0, 1);

 lcd.print("System running");
 

  } else {
    digitalWrite(ledPinblue, LOW);
  }

  
  if (x <= 15 && x > 10 ) {
    digitalWrite(ledPingrey, HIGH); Serial.print("grey   "); Serial.println(x);
       // Print a message to the LCD.
    lcd.setCursor(14, 0);
    lcd.println(x);

    lcd.setCursor(0, 0);
    lcd.print("Energy:  ");
     lcd.setCursor(0, 1);

 lcd.print("System running");
 

  } else {
    digitalWrite(ledPingrey, LOW);
  }

  if (x == 30) {
lcd.clear();
 Serial.print(" overloaded ");
  lcd.setCursor(0, 0);
 lcd.print("overload");
 lcd.setCursor(0, 1);
 lcd.print("Disconnected");

 
 if(x != 30){
  lcd.clear();
  }

  } else {}
 


  
  if (x <= 10 && x > 2) {
    digitalWrite(ledPinred, HIGH); Serial.print("red   "); Serial.println(x);
       // Print a message to the LCD.
    lcd.setCursor(14, 0);
    lcd.println(x);

    lcd.setCursor(0, 0);
    lcd.print("Energy:  ");
     lcd.setCursor(0, 1);

 lcd.print("System running");
 

  } else {
    digitalWrite(ledPinred, LOW);
  }


  
  if (x < 2 ) {
    lcd.clear();
    smile = true;

   // Print a message to the LCD.
    lcd.setCursor(14, 0);
    lcd.println(x);

    lcd.setCursor(0, 0);
    lcd.print(" Please recharge ");
     lcd.setCursor(0, 2);
 lcd.print("Disconnected");
 
    
  }



}

