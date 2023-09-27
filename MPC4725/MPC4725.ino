#include <Wire.h>
#include <Adafruit_MCP4725.h>
Adafruit_MCP4725 dac;
// Set this value to 9, 8, 7, 6 or 5 to adjust the resolution
#define DAC_RESOLUTION    (9)

int op2 = 2;
int op3 = 3;
int op4 = 4;

int op5;



int sbyte[] = {0x08, 0x04, 0x02, 0x01,0,0,0, 0};



float j;
float K;
void setup(void) {
  Serial.begin(9600);

  pinMode(op2, OUTPUT);
  pinMode(op3, OUTPUT);
  pinMode(op4, OUTPUT);
  pinMode(op5, OUTPUT);

  digitalWrite(op2, LOW);
  digitalWrite(op3, LOW);
  digitalWrite(op4, LOW);
  digitalWrite(op5, LOW);


  Serial.println("MCP4725A1 Test");
  // MCP4725A1 address is 0x62 (default) 
  // MCP4725A1 address is 0x63 (ADDR pin tied to VCC) 
  // MCP4725A1 address is 0x60 (ADDR pin tied to GND) 
  
}

void sencors2(float m) {
    dac.begin(0x61); //I have my ADDR pin connected to GND so address is 0x60
      Serial.print("Value for J:");
      Serial.println(m);
      dac.setVoltage((m*4095)/50, false);        //Set voltage to 1V
}

void sencors3(float m) {
    dac.begin(0x61); //I have my ADDR pin connected to GND so address is 0x60
      Serial.print("Value for K:");
      Serial.println(m);
      dac.setVoltage((m*4095)/50, false);        //Set voltage to 1
}

void sencors4(float m) {
    dac.begin(0x61); //I have my ADDR pin connected to GND so address is 0x60
      Serial.print("Value for J:");
      Serial.println(m);
      dac.setVoltage((m*4095)/50, false);        //Set voltage to 1V
}

void sencors5(float m) {
    dac.begin(0x61); //I have my ADDR pin connected to GND so address is 0x60
      Serial.print("Value for K:");
      Serial.println(m);
      dac.setVoltage((m*4095)/50, false);        //Set voltage to 1V
      Serial.print("Voltage Value:");
      Serial.println((m*4095)/50);
}

void shift_resiter(int num){
 digitalWrite(op4, LOW); // Pull the LATCH pin LOW to start sending data
  shiftOut(op2, op3, MSBFIRST, sbyte[num]); // Send data to the shift register
  digitalWrite(op4, HIGH); // Pull the LATCH pin HIGH to update the LEDs
  //Serial.println("out of shift_resiter");
}

void sencors() {
      K =0;
      j =100;  
  for (int i =0; i<=100;i++){
        
        sencors2(K);
        shift_resiter(0);
        sencors3(j);
        shift_resiter(1);
        sencors4(K);
        shift_resiter(2);
        sencors5(j);
        shift_resiter(3);
        K =K + 1 ;
        j =j -1;
      delay(500);
  };
}

void loop(void) {
    sencors();
}