
#include <Wire.h>
int maxByte = 30;
void setup() {
  Wire.begin(); // join i2c bus (address optional for master)
}

byte x = 0;

void loop() {
  Wire.beginTransmission(8); // transmit to device #8
  Wire.write("Energy = ");        // sends five bytes
  Wire.write(x); // sends one byte 
  Wire.endTransmission();    // stop transmitting

  x++;
  if (x > maxByte) x =0;
  delay(500);
}
