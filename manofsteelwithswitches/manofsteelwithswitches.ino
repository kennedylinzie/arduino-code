

#include <Stepper.h>

const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution
// for your motor



///////////

 int mouse=10 ;////// 10
 int dog=-10 ;///// -10

 ////////////genesis
 Stepper myforwardD(stepsPerRevolution, 9, 10, 11,12);
 Stepper mybackward(stepsPerRevolution,12, 11, 10, 9);

// initialize the stepper library on pins 8 through 11:
Stepper myforward(stepsPerRevolution, 9, 10, 11,12);
Stepper myStepper(stepsPerRevolution, 12, 11, 10, 9);

int stepCount = 0;         // number of steps the motor has taken
boolean dancing;
/*
////////////////////////.............sensor
#include "DHT.h"

#define DHTPIN 2     // what digital pin we're connected to

// Uncomment whatever type you're using!
//#define DHTTYPE DHT11   // DHT 11
#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21   // DHT 21 (AM2301)
DHT dht(DHTPIN, DHTTYPE);

#include<LiquidCrystal.h>
LiquidCrystal lcd(9, 8, 7, 6, 5, 4);
#define bulb 13
#define pwm 3
byte degree[8] = 
              {
                0b00011,
                0b00011,
                0b00000,
                0b00000,
                0b00000,
                0b00000,
                0b00000,
                0b00000
              };

 unsigned long previousMillis = 0;        // will store last time LED was updated

 */

// constants won't change :
const long interval =2000;
//const long interval2 =1000;
///////////////////////////////////////////
void setup() {
  // initialize the serial port:
  Serial.begin(9600);
/*
  ///////////////...........lcd setup
  lcd.begin(16, 2);
 lcd.createChar(1, degree);
 lcd.clear();
 lcd.print("   Fan Speed  ");
 lcd.setCursor(0,1);
 lcd.print("  Bulb ");
 delay(2000);
 analogWrite(pwm, 255);
 lcd.clear();
 lcd.print("Temperature");
 delay(1000);

  dht.begin();
  ///////////////............
  
     */

//zuma();
  
}

void loop() {


 thewalk();

/*
unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;


if (currentMillis - previousMillis >= 0 && currentMillis - previousMillis < interval ) 
{
  
}
//if (currentMillis - previousMillis >= 1000 && currentMillis - previousMillis < interval2)
 // {
 //   weatherman(); 
//}    

      */
   
     
    
  
  
  
}


void thewalk()
{
  if(stepCount < mouse)
  {
    forward();
    
    //weatherman();
    
  }if(stepCount  == mouse)
  {
    
    while(dog < mouse && stepCount != dog){
     
    backward();
     //weatherman();
    }
    
    }
  
 }


 void zuma(){
                       genesis_forward();
                       genesis_backward();
                       genesis_back_to_zero();
                     }




void backward(){

  

   // step one step:
  myStepper.step(1);
  Serial.print("steps:");
  Serial.println(stepCount);
  stepCount--;
  delay(500);
     
  }

  void forward(){
 
      // step one step:
   myforward.step(1);
  Serial.print("steps:");
  Serial.println(stepCount);
  stepCount++;
  delay(500);
   
    
 }
    
 void genesis_forward()
 {

    
  //////////////WAITING FOR TRIGERSS
   // step one step:
 myforwardD.step(1);
  Serial.print("steps:");
  Serial.println(stepCount);
  stepCount++;
  delay(500);

        
      mouse = 10;

  
 }

 void genesis_backward()
 {
 
  

  
  ///////////////WAITING FOR TRIGGERS
   // step one step:
 mybackward.step(1);
  Serial.print("steps:");
  Serial.println(stepCount);
  stepCount--;
  delay(500);

  
       dog = -11;
      
  
 }

 void genesis_back_to_zero()
  {
       while(stepCount != 0 )
       {
     myforwardD.step(1);
  Serial.print("steps:");
  Serial.println(stepCount);
  stepCount++;
  delay(500);
       }
    stepCount = 0;
  }




/*  
void weatherman()
{
  // Wait a few seconds between measurements.
  

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float humid = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float temp = dht.readTemperature();
 

  // Check if any reads failed and exit early (to try again).
  if (isnan(humid) || isnan(temp)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(temp, humid, false);

  //print to lcd
lcd.setCursor(0,0);
  lcd.print("Temperature:");
  lcd.print(temp);   // Printing temperature on LCD
  lcd.write(1);
  lcd.print("C");
  lcd.setCursor(0,1);


//temp check
 if(temp <37 )
    { 
      analogWrite(pwm, 0);
      digitalWrite(bulb, HIGH);
      lcd.print("Fan OFF            ");
     Serial.print("Fan OFF ");
     Serial.print("\t");
     Serial.print("bulb on");
     Serial.print("\t");
     Serial.print("Temperature=");
     Serial.print(temp);
     Serial.println(".*c");
     Serial.print(" ");
      delay(100);
    }
    
    else if(temp==37 && temp<=38.7)
    {
      analogWrite(pwm, 127);
      digitalWrite(bulb, HIGH);
      lcd.print("Fan Speed: 50%   ");
       Serial.print("Fan Speed: 50%   ");
       Serial.print("\t");
     Serial.print("bulb on");
     Serial.print("\t");
     Serial.print("Temperature=");
       Serial.print(temp);
       Serial.println(".*c");
       Serial.print(" ");
      delay(100);
    }
    
     else if(temp>39)
    {
      analogWrite(pwm, 255);
      digitalWrite(bulb, LOW);
      lcd.print("Fan Speed: 100%   ");
       Serial.print("Fan Speed: 100%   ");
        Serial.print("\t");
     Serial.print("bulb on");
     Serial.print("\t");
     Serial.print("Temperature=");
       Serial.print(temp);
       Serial.println(".*c");
       Serial.print(" ");
      delay(100);
    }
    
 // delay(3000);
  

}
*/
