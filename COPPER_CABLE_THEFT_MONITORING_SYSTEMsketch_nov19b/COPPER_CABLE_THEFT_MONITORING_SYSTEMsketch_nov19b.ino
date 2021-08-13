/* Analog Input
 Demonstrates analog input by reading an analog sensor on analog pin 0 and
 turning on and off a light emitting diode(LED)  connected to digital pin 13.
 The amount of time the LED will be on and off depends on
 the value obtained by analogRead().

 The circuit:
 * Potentiometer attached to analog input 0
 * center pin of the potentiometer to the analog pin
 * one side pin (either one) to ground
 * the other side pin to +5V
 * LED anode (long leg) attached to digital output 13
 * LED cathode (short leg) attached to ground

 * Note: because most Arduinos have a built-in LED attached
 to pin 13 on the board, the LED is optional.


 Created by David Cuartielles
 modified 30 Aug 2011
 By Tom Igoe

 This example code is in the public domain.

 http://arduino.cc/en/Tutorial/AnalogInput

 */




#include "Adafruit_FONA.h"

#define FONA_RX 2
#define FONA_TX 3
#define FONA_RST 4

// this is a large buffer for replies
char replybuffer[255];

// We default to using software serial. If you want to use hardware serial
// (because softserial isnt supported) comment out the following three lines 
// and uncomment the HardwareSerial line
#include <SoftwareSerial.h>
SoftwareSerial fonaSS = SoftwareSerial(FONA_TX, FONA_RX);
SoftwareSerial *fonaSerial = &fonaSS;

// Hardware serial is also possible!
//  HardwareSerial *fonaSerial = &Serial1;

// Use this for FONA 800 and 808s
Adafruit_FONA fona = Adafruit_FONA(FONA_RST);
// Use this one for FONA 3G
//Adafruit_FONA_3G fona = Adafruit_FONA_3G(FONA_RST);

uint8_t readline(char *buff, uint8_t maxbuff, uint16_t timeout = 0);

uint8_t type;



///////////////////////

unsigned long previousMillis = 0;        // will store last time LED was updated

// constants won't change :
const long interval = 5000; 

 
    // select the input pin for the potentiometer
int LED = 13; 
int LEDg = 12;  
int BUZZER = 10;

boolean react;
boolean go;


void setup() {



  while (!Serial);

  Serial.begin(115200);
  Serial.println(F("FONA basic test"));
  Serial.println(F("Initializing....(May take 3 seconds)"));

  fonaSerial->begin(4800);
  if (! fona.begin(*fonaSerial)) {
    Serial.println(F("Couldn't find FONA"));
    while (1);
  }
  type = fona.type();
  Serial.println(F("FONA is OK"));
  Serial.print(F("Found "));
  switch (type) {
    case FONA800L:
      Serial.println(F("FONA 800L")); break;
    case FONA800H:
      Serial.println(F("FONA 800H")); break;
    case FONA808_V1:
      Serial.println(F("FONA 808 (v1)")); break;
    case FONA808_V2:
      Serial.println(F("FONA 808 (v2)")); break;
    case FONA3G_A:
      Serial.println(F("FONA 3G (American)")); break;
    case FONA3G_E:
      Serial.println(F("FONA 3G (European)")); break;
    default: 
      Serial.println(F("???")); break;
  }
  
  // Print module IMEI number.
  char imei[16] = {0}; // MUST use a 16 character buffer for IMEI!
  uint8_t imeiLen = fona.getIMEI(imei);
  if (imeiLen > 0) {
    Serial.print("Module IMEI: "); Serial.println(imei);
  }


  
////////////////////////////////////
  // declare the ledPin as an OUTPUT:
    Serial.begin(9600);
  pinMode(  LED, OUTPUT);
   pinMode(BUZZER, OUTPUT);
   react =false;
   go = false;
   
}

void loop() {



 unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;


    if(react == true)
    {
      
        fona.sendSMS("+265888158673", "System  Reading SHORT CIRCUIT");   
      
      
      }
        if(go == true)
    {
      
        fona.sendSMS("+265888158673", "System  Reading OPEN CIRCUIT");
      
      
      }

        


  }





  
    int InputSignal = analogRead(A0);
    float voltage = InputSignal*(3.50/1023.0);
    Serial.print(InputSignal);
    Serial.print("\t");
    Serial.println(voltage);
  // read the value from the sensor:
  
  if( voltage >= 0.60 && voltage <= 0.63 ){
    Serial.print("System  Reading Normal.... \t");
    digitalWrite(12, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);              // wait for a second
  digitalWrite(12, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);       
  }
  else if(voltage == 0 ){ //SHORT CIRCUT 
  Serial.print("System  Reading SHORT CIRCUIT.... \t");
        react = true;
    digitalWrite(10, HIGH);  
   digitalWrite(13, HIGH); 
  delay(1000);              
  digitalWrite(10, LOW); 
  digitalWrite(13, LOW);
  delay(1000);       
  }
  if(voltage != 0){react =false;}

  
 else if(voltage >= 2.0 && voltage <= 3.5){ //OPEN CIRCUT
  Serial.print("System  Reading OPEN CIRCUIT.... \t");
        go =true;
    digitalWrite(10, HIGH);
  digitalWrite(13, HIGH);  
  delay(600);             
  digitalWrite(10, LOW); 
  digitalWrite(13, LOW);
  delay(600);       
  }//else{go = false;}

  if(!voltage >= 2.0 && !voltage <= 3.5){ go = false;};

  
  
}



