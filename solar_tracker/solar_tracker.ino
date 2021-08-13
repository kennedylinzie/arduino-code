//code for tracking the position of the sun


#include <Stepper.h>

// 
//const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution
// for your motor

 int mouse;
 int dog;
 
////////////genesis
 Stepper myforwardD(stepsPerRevolution, 8, 9, 10, 11);
 Stepper mybackward(stepsPerRevolution, 11, 10, 9, 8);

// initialize the stepper library on pins 8 through 11:
Stepper myforward(stepsPerRevolution, 8, 9, 10, 11);
Stepper myStepper(stepsPerRevolution, 11, 10, 9, 8);

int stepCount = 0;         // number of steps the motor has taken





int eastLDR=0;                //Pin at which LDR is connected
  int westLDR=1;                //Pin at which LDR is connected
    int tolerance=5;                  //initializing variable for error between the LDR's
 

void setup() {
  pinMode(eastLDR, INPUT);
    pinMode(westLDR, INPUT);
  Serial.begin(9600);
     delay(2000);
/////////////////////////////////////..............
         void GENESIS(){
                        genesis_forward();
                        genesis_backward();
                        genesis_back_to_zero();
                       }
                       
///////////////////////////////////................     
}
 
void loop() {
  // put your main code here, to run repeatedly:

int eastValue = analogRead(eastLDR); // reading value from east LDR
  Serial.print("East LDR resistance =");
    Serial.print(eastValue);
  
int westValue = analogRead(westLDR); // reading value from west LDR
  Serial.print("\t");
    Serial.print("West LDR resistance=");
      Serial.println(westValue);
      
int difference1= abs(eastValue - westValue);   // Calculating the difference between the LDR's
  int difference2= abs(westValue - eastValue);

if((difference1 <= tolerance) || (difference2 <= tolerance))
{
    //if the difference is under the error then do nothing
}
else
{    
    if(eastValue > westValue)
    
    {
  
       moveEast();          //apa i don't know to set limit coz in the blankets we are comparing ma values a ma ldr's instead dog and mouse limits so u should work on that.
        delay(1000);                            // waits 1 second for the servo to reach the position
    }
    
    if(eastValue < westValue) 
    {
      
         moveWest();      ////apaso i don't know to set limit coz in the blankets we are comparing ma values a ma ldr's instead dog and mouse limits so u should work on this.
      delay(2000);                               // waits 2 seconds for the servo to reach the position
  }


    }}

    
///////////// move weat
    void moveWest(){

      while(stepCount <= -10)
      {
   // step one step:
  myStepper.step(1);
  Serial.print("steps:");
  Serial.println(stepCount);
  stepCount--;
  delay(500);
        
      }

  }
////////////move east
  void moveEast(){

    while(stepCount <= 10 )
    {
      // step one step:
   myforward.step(1);
  Serial.print("steps:");
  Serial.println(stepCount);
  stepCount++;
  delay(500);
    }
  
  }

 ///////////////////////..............
 void genesis_forward()
 {

  //////////////WAITING FOR TRIGERSS
   // step one step:
 myforwardD.step(1);
  Serial.print("steps:");
  Serial.println(stepCount);
  stepCount++;
  delay(500);
        
      
      dog = 10;
  
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
        
     
      mouse = -10;
  
 }

  genesis_back_to_zero()
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


 
 //////////////////////..............
