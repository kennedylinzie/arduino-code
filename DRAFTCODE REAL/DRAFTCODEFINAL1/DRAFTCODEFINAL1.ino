
#//include<Sim800l.h>
#include<SoftwareSerial.h>
SoftwareSerial Serial1(2,3);
#include<LiquidCrystal.h>
LiquidCrystal lcd(7,8,9,10,11,12);
int led=13;
int flag=0;
String str="";
#define motor 5
#define sensor 13

/////
unsigned char Buff[250];
 unsigned char BuffIndex;
 boolean hold;

void setup()
{

  Serial1.begin(9600);
  Serial.begin(9600);

   Serial.println("GSM ");
    delay(3000);
    Serial.println("AT+CMGF=1");
    delay(3000);
   Serial.println("AT+CNMI=2,2,0,0,0");
    memset(Buff, '\0', 250);    // Initialize the string
    BuffIndex=5;
  ////////////
  lcd.begin(16,2);
  
  pinMode(led, OUTPUT);
  pinMode(motor, OUTPUT);
  pinMode(sensor, INPUT_PULLUP);
  lcd.print("Water Irrigaton");
  lcd.setCursor(4,1);
  delay(2000);
  lcd.clear();
  lcd.print("Circuit Digest");
  lcd.setCursor(0,1);
  lcd.print("Welcomes You");
  delay(2000);
  gsmInit();
  lcd.clear();
  lcd.print("System Ready");
  hold =true;
}
void loop()
{

receiveMSG(); // reveive message function

  if(hold == true){
    
    lcd.setCursor(0,0);
    lcd.print("Automatic Mode    ");
    if(digitalRead(sensor)==1 && flag==0)
    {
      delay(1000);
      if(digitalRead(sensor)==1)
      {
        digitalWrite(led, HIGH);
        sendSMS("Low Soil Moisture detected. Motor turned ON");
        lcd.begin(16,2);
        lcd.setCursor(0,1);
        lcd.print("Motor ON    ");
        digitalWrite(motor, HIGH);
        delay(2000);
        flag=1;
      }
    }
    else if(digitalRead(sensor)==0 && flag==1)
    {
      delay(1000);
      if(digitalRead(sensor)==0)
      {
        digitalWrite(led, LOW);
        sendSMS("Soil Moisture is Normal. Motor turned OFF");
        digitalWrite(motor, LOW);
        lcd.begin(16,2);
        lcd.print("Motor OFF");
        lcd.setCursor(0,1);
        lcd.print("Motor OFF");
        delay(2000);
        flag=0;
      }
    }

     if(hold == false){lcd.clear();}

  }else{lcd.clear();
  lcd.setCursor(0,1);
        lcd.print("system on hold");
       
  
  }
    //////////////////
}
 
void sendSMS(String msg)
{
  lcd.clear();
  lcd.print("Sending SMS");
  Serial1.println("AT+CMGF=1");
  delay(500);
  Serial1.print("AT+CMGS=");
  Serial1.print('"');
  Serial1.print("+265999297746");    // number
  Serial1.print('"');
  Serial1.println();
  delay(500);
  Serial1.println(msg);
  delay(500);
  Serial1.write(26);
  delay(1000);
  lcd.clear();
  lcd.print("SMS Sent");
  delay(1000);
  lcd.begin(16,2);
}
void gsmInit()
{
  lcd.clear();
  lcd.print("Finding Module..");
  boolean at_flag=1;
  if(at_flag)
  {
    Serial1.println("AT");
    if(Serial1.available()>0)
    {
      if(Serial1.find("OK"))
      at_flag=0;
    }
    delay(1000);
  }
  Serial1.println("ATEO");
  lcd.clear();
  lcd.print("Finding Network..");
  boolean net_flag=1;
  if(net_flag)
  {
    Serial1.println("AT+CPIN?");
    if(Serial1.available()>0)
    {
      if(Serial1.find("READY"))
      net_flag=0;
      //break;
    }
    delay(1000);
  }
   Serial1.println("AT+CNMI=2,2,0,0,0");
   delay(1000);
   Serial1.println("AT+CMGF=1");
   delay(1000);
   Serial1.println("AT+CSMP=17,167,0,0");
   lcd.clear();
   Serial1.flush();
}


void receiveMSG()
{
  
   if(1)
      {
          if(Serial1.available()>0)
          {
              Buff[BuffIndex] = Serial1.read();    
          
              if( (Buff[BuffIndex-3] == 'h') && (Buff[BuffIndex-2] == 'o') && (Buff[BuffIndex-1] == 'l') && (Buff[BuffIndex] == 'd')  )
              {
                  Serial.println("Command 1"); 
                  hold =false;   
              }
              if( (Buff[BuffIndex-4] == 's') && (Buff[BuffIndex-3] == 't') && (Buff[BuffIndex-2] == 'a') && (Buff[BuffIndex-1] == 'r') && (Buff[BuffIndex] == 't') )
              {
                  Serial.println("Command 2"); 
                  hold =true; 
                  lcd.clear();  
              }
              
          
          
              BuffIndex++;
              if(BuffIndex>250) 
              {
                  BuffIndex=5;
              }
          }
      }
  
  
}
  
