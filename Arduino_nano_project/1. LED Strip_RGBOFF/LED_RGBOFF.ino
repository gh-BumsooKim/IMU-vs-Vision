#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel LEDstrip = Adafruit_NeoPixel(100, 6, NEO_GRB + NEO_KHZ800);

//LED STRIP : D6, 5V, GND
//BUTTON : D2, GND

void setup() 
{
  pinMode(2,INPUT_PULLUP);
  pinMode(5,OUTPUT);
  
  LEDstrip.setBrightness(50);
  LEDstrip.begin();  
}

int L=0;

void loop() {
  // switch controller      
  if(digitalRead(2) == HIGH)
  {
    LEDstrip.clear();
  }
  else
  {  
    for(int i=0; i<100; i++)
    {
      if(L>3)
      {
        L=0;
      } 
      if(L==0)
      {
        LEDstrip.setPixelColor(i,250,0,0); //R
        //LEDstrip.setPixelColor(i,250-20*i,10*i,0);
      }
      if(L==1)
      {
        LEDstrip.setPixelColor(i,0,250,0); //G
        //LEDstrip.setPixelColor(i,5*i,250-10*i,20*i);
      }
      if(L==2)
      {
        LEDstrip.setPixelColor(i,0,0,250); //B
        //LEDstrip.setPixelColor(i,50,10*i,255-5*i);
      }
      //
      if(L==3)
      {
        LEDstrip.setPixelColor(i,120,0,120); //B
        //LEDstrip.setPixelColor(i,5*i,50+10*i,30);
      } 
      LEDstrip.show();
      delay(5);
    }
    L+=1;
  }
}
