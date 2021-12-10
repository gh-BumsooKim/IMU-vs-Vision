import org.firmata.*;
import processing.serial.*;
import cc.arduino.*;

Arduino ard;
PImage bg;

color off = color(4, 79, 111);
color input_on = color(51, 204, 204);
color output_on = color(255, 0, 102);

int[] values = {Arduino.LOW, Arduino.LOW, Arduino.LOW, Arduino.LOW, Arduino.LOW, Arduino.LOW, Arduino.LOW, Arduino.LOW};

void setup(){
  size(921, 659);
  bg = loadImage("arduino.png");
  
  //println(Arduino.list());
  
  ard = new Arduino(this, Arduino.list()[0], 9600);
  
  // Output Pins
  for (int i=0; i<13; i++){
    if (i<7) { ard.pinMode(i, ard.OUTPUT); }
    else {     ard.pinMode(i, ard.INPUT);  } 
  }
}

void draw(){
  background(bg);
  
  stroke(input_on);
  
  // Input pins / Draw a filled box
  for (int i=8; i<=13; i++){
    if (ard.digitalRead(i) == Arduino.HIGH){
      fill(input_on);
    } else { fill(off); }
    
    rect(815 - 30*i, 30, 20, 20);
  }
  
  // Output pins / Draw a filled box
  for (int i=0; i<=7; i++){
    if (values[i] == Arduino.HIGH){
      fill(output_on);
    } else { fill(off); }
    
    rect(835 - 30*i, 30, 20, 20);
  }
}

void mousePressed(){
  int pin = (855-mouseX)/30;
  
  println(pin);
  
  if (0 <= pin && pin < 8){
    if (values[pin] == Arduino.LOW){
      ard.digitalWrite(pin, Arduino.HIGH);
      values[pin] = Arduino.HIGH;
    } else {
      ard.digitalWrite(pin, Arduino.LOW);
    values[pin] = Arduino.LOW; }
  }
}
