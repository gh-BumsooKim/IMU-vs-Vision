// using adafruit neopixl 1.10.0

void led_on(int idx){
  ledstrip.clear();

  for(int j=0; j<10; j++){
    ledstrip.setPixelColor(idx+j,25,idx+50,30);}
  
  ledstrip.show();
  delay(10);
}
