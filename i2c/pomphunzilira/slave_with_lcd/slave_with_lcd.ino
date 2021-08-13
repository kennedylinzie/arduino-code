#include <Wire.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);


int LED = 13;
int threshold = 15;



void setup() {
  Wire.begin(8);                // join i2c bus with address #8
  Wire.onReceive(receiveEvent); // register event
  Serial.begin(9600);           // start serial for output
  lcd.begin(16, 2);
  pinMode(LED, OUTPUT);
}

void loop() {
  delay(100);
}

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int howMany) {
  while (1 < Wire.available()) { // loop through all but the last
    char c = Wire.read(); // receive byte as a character
    Serial.print(c);  // print the character
    //lcd.setCursor(0,0);
    //lcd.print(c);
  }
  int x = Wire.read();    // receive byte as an integer
         Serial.println(x); // print the integer
         //lcd.setCursor(10,0);
         //lcd.print(x);

  if (x > threshold ) {
    digitalWrite(LED, HIGH);
    delay(500);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Energy = Normal");
    lcd.setCursor(0,1);
    lcd.print("balance");
    lcd.setCursor(8,1);
    lcd.print(":");
    lcd.setCursor(10,1);
    lcd.print(x);
    
  }



   if (x < threshold){
    digitalWrite(LED, LOW);
     delay(500);
     lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Disconnected");
    
    lcd.setCursor(0,1);
    lcd.print("Reason-Overload");
  
   }
}

