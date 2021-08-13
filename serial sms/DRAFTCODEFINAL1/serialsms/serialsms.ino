

#include<SoftwareSerial.h>
SoftwareSerial Serial1(2,3); //transmitter and receiver pins TX IS 3..RX IS 2
                             //CONNECT RESET ON MODULE TO RESET ON ARDUINO





void setup()
{
 
  Serial1.begin(9600);
    Serial.begin(9600);
 
  gsmInit();
 
  sendSMS("hi kenny");
}
void loop()
{
}
 
void sendSMS(String msg)
{
 
  Serial1.println("AT+CMGF=1");
  delay(500);
  Serial1.print("AT+CMGS=");
  Serial1.print('"');
  Serial1.print("+265888158673");    // number
  Serial1.print('"');
  Serial1.println();
  delay(500);
  Serial1.println(msg);
  delay(500);
  Serial1.write(26);
  delay(1000);
  
}
void gsmInit()
{
 
  boolean gms_fg=1;
  if(gms_fg)
  {
    Serial1.println("AT");
    if(Serial1.available()>0)
    {
      if(Serial1.find("OK"))
      gms_fg=0;
    }
    delay(1000);
  }
  Serial1.println("ATEO");
 
  boolean gsm_nt=1;
  if(gsm_nt)
  {
    Serial1.println("AT+CPIN?");
    if(Serial1.available()>0)
    {
      if(Serial1.find("READY"))
     gsm_nt=0;
     // break;
    }
    delay(1000);
  }
   Serial.println("AT+CNMI=2,2,0,0,0");
   delay(1000);
   Serial.println("AT+CMGF=1");
   delay(1000);
   Serial.println("AT+CSMP=17,167,0,0");
  
   Serial1.flush();
}

