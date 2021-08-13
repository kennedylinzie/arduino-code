/*
Traffic lights control systems
by: 
Baston Hullet Longwe
Rage Dafter
Debbie Silungwe
Charity Kumpama
Kennedy Linzie
*/
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(8, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(13, HIGH);   // Car stop
  digitalWrite(12, LOW);    
  digitalWrite(11, LOW);    
  digitalWrite(10, LOW);
  digitalWrite(8, HIGH);    // Pedestrians cross
  delay(5000);              // wait for a 5 milliseconds
  digitalWrite(13, LOW);    
  digitalWrite(12, HIGH);   // Car get ready to cross
  digitalWrite(11, LOW);  
  digitalWrite(10, LOW);
  digitalWrite(8, HIGH);    //Pedestrians cross
  delay(2000);              // wait for 2 milliseconds
  digitalWrite(13, LOW);   
  digitalWrite(12, LOW);    
  digitalWrite(11, HIGH);   // Car cross
  digitalWrite(10, HIGH);   // Pedestrians stop
  digitalWrite(8, LOW); 
  delay(5000);              // wait for a 5 milliseconds
  digitalWrite(13, LOW);    
  digitalWrite(12, HIGH);   // Car get ready to stop
  digitalWrite(11, LOW);  
  digitalWrite(10, HIGH);    // Pedestrians stop
  digitalWrite(8, LOW); 
  delay(2000);              // wait for a 2 milliseconds
}
  
