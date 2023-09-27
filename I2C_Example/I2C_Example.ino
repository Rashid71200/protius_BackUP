#include <Wire.h>
// Set this value to 9, 8, 7, 6 or 5 to adjust the resolution
#define X_Axis_Register_DATAX0 0x32 // Hexadecima address for the DATAX0 internal register.
#define X_Axis_Register_DATAX1 0x33 // Hexadecima address for the DATAX1 internal register.
#define Power_Register 0x2D // Power Control Register
int ADXLAddress = 0x60; // Device address in which is also included the 8th bit for selecting the mode, read in this case.

int X0,X1,X_out;


//#define DAC_RESOLUTION    (9)
float j;



void setup() {
  Wire.begin(); // Initiate the Wire library
  Serial.begin(9600);
  delay(100);
  // Enable measurement
  Wire.beginTransmission(ADXLAddress);
  Wire.write(Power_Register);
  // Bit D3 High for measuring enable (0000 1000)
  Wire.write(8);  
  Wire.endTransmission();


  // MCP4725A1 address is 0x62 (default) 
  // MCP4725A1 address is 0x63 (ADDR pin tied to VCC) 
  // MCP4725A1 address is 0x60 (ADDR pin tied to GND) 
  //dac.begin(0x60); //I have my ADDR pin connected to GND so address is 0x60

}

void loop() {
  Wire.beginTransmission(ADXLAddress); // Begin transmission to the Sensor 
  //Ask the particular registers for data
  Wire.write(X_Axis_Register_DATAX0);
  Wire.write(X_Axis_Register_DATAX1);
  
  Wire.endTransmission(); // Ends the transmission and transmits the data from the two registers
  
  Wire.requestFrom(ADXLAddress,2); // Request the transmitted two bytes from the two registers
  
  if(Wire.available()<=2) {  // 
    X0 = Wire.read(); // Reads the data from the register
    X1 = Wire.read();   
  }
  
  Serial.print("X0= ");
  Serial.print(X0);
  Serial.print("   X1= ");
  Serial.println(X1);
}