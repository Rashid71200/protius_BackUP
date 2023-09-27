#include <MCP3008.h>


// define pin connections
#define CS_PIN 4
#define CLOCK_PIN 7
#define MOSI_PIN 5
#define MISO_PIN 6

//int led = 4;

// put pins inside MCP3008 constructor
MCP3008 adc(CLOCK_PIN, MOSI_PIN, MISO_PIN, CS_PIN);

void setup() {
 
 // open serial port
 Serial.begin(9600);
 //pinMode(led, OUTPUT);
  
}


void loop() {
  
  
  int val = adc.readADC(0); // read Chanel 0 from MCP3008 ADC
  Serial.println(val);
  /*
  digitalWrite(led, HIGH);
  delay(100);
    digitalWrite(led, LOW);
  delay(100);
  
  // iterate thru all channels
  
  for (int i=0; i<8; i++) {
   int val = adc.readADC(i);
   Serial.print(val);
   Serial.print("\t");
   }
   Serial.println("");
  */
  
}