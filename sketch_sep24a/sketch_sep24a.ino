#include "SPI.h"
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"

#define BOXSIZE 25
//#include "dragon.h"

// For the Adafruit shield, these are the default.
//#define TFT_DC 9
//#define TFT_CS 10

// Use hardware SPI (on Uno, #13, #12, #11) and the above for CS/DC
//Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);
// If using the breakout, change pins as desired
Adafruit_ILI9341 tft = Adafruit_ILI9341(8, 9, 11, 13,10, 12);

int potPin = A5;
int xvalue;
int xvalue1;
int xvalueX;



int potPin1 = A4;
int yvalue;
int yvalue1;
int yvalueX;



int potPin2 = A3;
int value2;
int value12;
int valueX2;


int potPin3 = A2;
int value3;
int value13;
int valueX3;

void setup() {
  Serial.begin(9600);
  pinMode(potPin, INPUT);

  pinMode(potPin1, INPUT);

  pinMode(potPin2, INPUT);

  pinMode(potPin3, INPUT);


  tft.begin();


    tft.setRotation(1);
  //tft.fillRect(0, 0, BOXSIZE*6, BOXSIZE, ILI9341_RED);
  //tft.fillRect(0, BOXSIZE, BOXSIZE*6, BOXSIZE, ILI9341_YELLOW);
  //tft.fillRect(0, BOXSIZE*2, BOXSIZE*6, BOXSIZE, ILI9341_GREEN);
  //tft.fillRect(0, BOXSIZE*3, BOXSIZE*6, BOXSIZE, ILI9341_CYAN);
  //tft.fillRect(0, BOXSIZE*4, BOXSIZE*6, BOXSIZE, ILI9341_BLUE);
  //tft.fillRect(0, BOXSIZE*5, BOXSIZE*6, BOXSIZE, ILI9341_MAGENTA);

  tft.setCursor(7, 5);
  tft.setTextColor(ILI9341_WHITE);  tft.setTextSize(2);
  tft.println("Machine Efficiency");
  tft.setCursor(12, 23);
  tft.setTextColor(ILI9341_WHITE);  tft.setTextSize(2);
  tft.println("Monitoring System");

      tft.setCursor(15, BOXSIZE*2);
      tft.setTextColor(ILI9341_RED);  tft.setTextSize(2);
      tft.print("Water Flow:");

      tft.setCursor(15, BOXSIZE*3);
      tft.setTextColor(ILI9341_RED);  tft.setTextSize(2);
      tft.print("Compressed Air:");


      tft.setCursor(15, BOXSIZE*4);
      tft.setTextColor(ILI9341_RED);  tft.setTextSize(2);
      tft.print("Gas Flow:");


      tft.setCursor(15, BOXSIZE*5);
      tft.setTextColor(ILI9341_RED);  tft.setTextSize(2);
      tft.print("Streem Flow:");
}


void loop(void) {
  xvalue = analogRead(potPin);
  yvalue = analogRead(potPin1);
  value2 = analogRead(potPin2);
  value3 = analogRead(potPin3);

    if (xvalue != xvalue1) {
      tft.fillRect(230, BOXSIZE*2, BOXSIZE*2, (BOXSIZE+10)/2, ILI9341_BLACK);
      xvalueX = map(xvalue, 0, 1023, 0, 100);
      tft.setCursor(230, BOXSIZE*2);
      tft.setTextColor(ILI9341_RED);  tft.setTextSize(2);
      //tft.print(Pot_value);
      
      tft.print(xvalueX);
      Serial.print(xvalueX);

      xvalue1 = xvalue;
      delay(10);
  }

    if (yvalue != yvalue1) {
      tft.fillRect(230, BOXSIZE*3, BOXSIZE*2, (BOXSIZE+10)/2, ILI9341_BLACK);
      yvalueX = map(yvalue, 0, 1023, 0, 100);
      tft.setCursor(230, BOXSIZE*3);
      tft.setTextColor(ILI9341_RED);  tft.setTextSize(2);
      //tft.print(Pot_value);
      
      tft.print(yvalueX);
      Serial.print(yvalueX);

      yvalue1 = yvalue;
      delay(10);
  }



      if (value2 != value12) {
      tft.fillRect(230, BOXSIZE*4, BOXSIZE*2, (BOXSIZE+10)/2, ILI9341_BLACK);
      valueX2 = map(value2, 0, 1023, 0, 100);
      tft.setCursor(230, BOXSIZE*4);
      tft.setTextColor(ILI9341_RED);  tft.setTextSize(2);
      //tft.print(Pot_value);
      
      tft.print(valueX2);
      Serial.print(valueX2);

      value12 = value2;
      delay(10);
  }


      if (value3 != value13) {
      tft.fillRect(230, BOXSIZE*5, BOXSIZE*2, (BOXSIZE+10)/2, ILI9341_BLACK);
      valueX3 = map(value3, 0, 1023, 0, 100);
      tft.setCursor(230, BOXSIZE*5);
      tft.setTextColor(ILI9341_RED);  tft.setTextSize(2);
      //tft.print(Pot_value);
      
      tft.print(valueX3);
      Serial.print(valueX3);

      value13 = value3;
      delay(10);
  }
  delay(10);
}