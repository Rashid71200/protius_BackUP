#include <Wire.h>             //wire library
#include <Adafruit_MCP4725.h> // MCP4725 library from adafruit
#define analogVin A0          // Analog voltage input to A0

Adafruit_MCP4725 MCP4725; 

void setup(void) {
  Serial.begin(9600);
  MCP4725.begin(0x60); // Default I2C Address of MCP4725 breakout board (sparkfun)   If not try 0x61 or 0x62
  
}

void loop(void) {
  
    uint32_t MCP4725_value;
    int adcValueRead = 0;
    float voltageRead = 0;
    
    float MCP4725_expected_output;
    
   
    for (MCP4725_value = 1; MCP4725_value <= 100; MCP4725_value = MCP4725_value + 1)
    {
      MCP4725.setVoltage(((MCP4725_value * 4096.0)/50.0), false);
      Serial.print(((5.0/4096.0) * (MCP4725_value * MCP4725_value)/5.0));
      Serial.print("  ");
      Serial.println((MCP4725_value * MCP4725_value)/5.0);
      delay(250);
    }    
}