#include <Adafruit_NeoPixel.h>
#include <PCM.h>

Adafruit_NeoPixel LEDstrip = Adafruit_NeoPixel(100, 6, NEO_GRB + NEO_KHZ800);

const unsigned char LAZER[] PROGMEM = {129, 128, 128, 1...(ommited)};

void setup() 
{
  pinMode(2,INPUT_PULLUP);
  pinMode(5,OUTPUT);
  
  LEDstrip.setBrightness(50);
  LEDstrip.begin();  
  
  //startPlayback(LAZER, sizeof(LAZER));
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
    if(L!=3)
    {
      startPlayback(LAZER, sizeof(LAZER));
    }  
    for(int i=0; i<100; i++)
    {
      if(L>3)
      {
        L=0;
      } 
      if(L==0)
      {
        LEDstrip.setPixelColor(i,255,0,0); //R
        //LEDstrip.setPixelColor(i,250-20*i,10*i,0);
        //startPlayback(LAZER, sizeof(LAZER));
      }
      if(L==1)
      {
        LEDstrip.setPixelColor(i,0,255,0); //G
        //LEDstrip.setPixelColor(i,5*i,250-10*i,20*i);
        //startPlayback(LAZER, sizeof(LAZER));
      }
      if(L==2)
      {
        LEDstrip.setPixelColor(i,0,0,255); //B
        //LEDstrip.setPixelColor(i,50,10*i,255-5*i);
        //startPlayback(LAZER, sizeof(LAZER));
      }
      if(L==3)
      {
        //LEDstrip.setPixelColor(i,120,0,120); //B
        //LEDstrip.setPixelColor(i,5*i,50+10*i,30);
        //startPlayback(LAZER, sizeof(LAZER));
      }        
      LEDstrip.show();
      delay(5);
    }
    L+=1;
  }
}
