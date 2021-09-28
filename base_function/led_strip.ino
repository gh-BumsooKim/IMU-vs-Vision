#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel ledstrip = Adafruit_NeoPixel(100, 6, NEO_GRB + NEO_KHZ800);

//LED STRIP : D6, 5V, GND
//BUTTON : D2, GND

void setup() 
{
  pinMode(2,INPUT_PULLUP);
  pinMode(5,OUTPUT);
  
  ledstrip.setBrightness(50);
  ledstrip.begin();  
}

int L=0;

void loop() {
  for(int i=0; i<100; i++)
  {
    ledstrip.setPixelColor(i,5*i,50+10*i,30);
  } 
  ledstrip.show();
  
  delay(5);
  }
}
