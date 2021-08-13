#include <Wire.h>


#define pushbutton A0
#define stickswitch A1
int buttonstate = 0;
int  switchstate =0;
  
unsigned long previousMillis = 0;
const long interval = 2000;

byte x = 30;
void setup() {
  // put your setup code here, to run once:

Wire.begin();
pinMode(pushbutton, INPUT);
pinMode(stickswitch, INPUT);



}

void loop() {
  // put your main code here, to run repeatedly:
buttonstate = digitalRead(pushbutton);
//Serial.print("button state =");
//Serial.print(buttonstate);
switchstate = digitalRead(stickswitch);
//Serial.print("\t");
//Serial.print("switchstate =");
//Serial.print(switchstate);


unsigned long currentMillis = millis();



if ( (currentMillis - previousMillis >= interval) && (buttonstate == HIGH && switchstate == HIGH) ){

    SendDisconnect();
    
  // Serial.print("\t");
   //Serial.println("Disconnect overload");
   
   
  }
  if (  (currentMillis - previousMillis >= interval)&& (buttonstate == HIGH && switchstate == LOW) ){

    SendBalance();
    
   //Serial.print("\t");
   //Serial.println("Bulb on");
    
    }
    
}


void SendBalance() {
  Wire.beginTransmission(8); // transmit to device #8
  Wire.write("Energy Level= ");        // sends five bytes
  Wire.write(x); // sends one byte 
  Wire.endTransmission();    // stop transmitting

  x--;
  if (x != 0){
  if (x < 0) x =30;}
  delay(1000);
}

void SendDisconnect() {
  Wire.beginTransmission(8); // transmit to device #8
  Wire.write("Overload ");// sends five bytes
  Wire.write("Disconnected"); 
  Wire.endTransmission();    // stop transmitting

    delay(500);
}

