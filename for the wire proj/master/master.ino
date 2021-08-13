
#include <Wire.h>


unsigned long previousMillis = 0;  //will stole the last time the code was excecuted
const long interval = 1500; //the interval at which code  excecutes 1000 = 1 mili second
//you can inclease or decrease this depending with the rate at which you need the the change to happen

int maxByte = 0; //value used to compare the x value
const int button1Pinnonstiky = 2;  // pushbutton non sticky pin the red one
const int buttonsticky = 7;  // pushbutton sticky button pin the white one


int buttonStatenon = 0; // store the read value from the input of the none stick button
int btnsticky = 0;  // store the read value from the input of the sticky button  


 boolean goAHEAD ; //this value is used to set count in motion if the red button is pressed the changes to this value help with the transition



void setup() {
  Serial.begin(9600);
  // Set up the pushbutton pins to be an input:
  pinMode(button1Pinnonstiky, INPUT); se
   pinMode(buttonsticky, INPUT);
   
  
  Wire.begin(); // join i2c bus (address optional for master)
  goAHEAD = true; //so initialy this value is set to true for 
}

byte x = 30; //the value that is reduced to 0 and at same time being sent to the slave arduino for other uses
byte k =30; // the value that is pushed to the slave salve to force the overload when white button is pressed

void loop() {

  


  // read the state of the pushbutton value:
   buttonStatenon = digitalRead(button1Pinnonstiky);
btnsticky = digitalRead(buttonsticky);

//this   current millis will store the value of the milliseconds counted since the system has been running
    unsigned long currentMillis = millis();
/*
now after every 1500 millisecons this block will excecute....how this code below works
 the code will check currentMillis - previousMillis >= interval every 1500 and the value will be stored in previous millis
this value will have a uniform increment value since the value will be in maultiple it will always be true
*/
  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;
  
    if( buttonStatenon != HIGH) //check red button is clicked if the button is clicked excecute
{
  Serial.println(" thank you!!!!!!");
    Serial.println(goAHEAD);
   goAHEAD =false;//set this boolean that was initially true to false
  
  }
if( goAHEAD == false) // now that its false this code will run
{ 
  if(btnsticky  == HIGH){ //we ccheck if the red button is clicked if so
   
  Wire.beginTransmission(8); // transmit to device #8
 Wire.write("kennedy"); ///send to arduino this charcter chain
  Wire.write(k);  // send k which is  = 30 to the arduino slave
  Wire.endTransmission();    // stop transmitting
  
    
    }else{ //if overload not pressed
 Wire.beginTransmission(8); // transmit to device #8
  Wire.write("Energy = ");  ///send to arduino this charcter chain     
  Wire.write(x); // send x which carries a changing value from 30 - 0 to the slave
  Wire.endTransmission();    // stop transmitting
  // when x is redusing from 30 to zero 
  //while sending these numbers to slave 

  x--;
   Serial.println(x);            
  if (x == maxByte){  //soooooo when x is the same as maxBYTE WHICH is 0 to zero          
    goAHEAD =true; //this will be set back to true thereby killing the funtion as a whole turning it off
     Serial.println("done");
     
  }
 
    }
 }

    
  }


  
  
 
 


  
}
