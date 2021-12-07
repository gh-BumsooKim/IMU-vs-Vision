import processing.sound.*;

SinOsc osc; // Sine Wave Oscillator

String[] scale_name =  {"Do", "Re", "Mi", "Fa", "Sol","La", "Si", "Do"};
int[] scale =       {60, 62, 64, 65, 67, 69, 71, 72};
int[] scale_sharp = {61, 63, 0,  66, 68, 70, 0,  73}; // idx 2 and 6 is not used.

Serial myPort;
String val;
int idx;

///////////////////////////
// user defined function //
///////////////////////////

void drawPiano(){
  stroke(1);
  // White Part
  for(int i=0; i<8; i++){
    //fill(255-i*16, i*32, i*5); // visualization
    fill(255);
    rect(i*width/8, 0, width/8, height);
  }
  
  // Black Part
  for(int i=0; i<8; i++){
    if(i!=2 && i!=6){
      fill(0);
      rect(i*width/8 + width/12, 0, width/12, height-150);
    }
  }
}

void playPiano(int i){
  // pressed effect
  fill(70);
  rect(i*width/8 + width/12, 0, width/12, height-150);
  
  // notated to circle
  fill(255);
  noStroke();
  circle((i+1)*width/8, height-200, 30);
  
  if (idx >= 0) { osc.play(pow(2, ((scale_sharp[i]-69)/12.0))*440, 1); }
}

int whichPressed(String val){
  int idx;
  if (val.startsWith("Do_sharp"))      { idx = 0; }
  else if (val.startsWith("Re_sharp")) { idx = 1; }
  else if (val.startsWith("Fa_sharp")) { idx = 3; }
  else if (val.startsWith("Sol_sharp")){ idx = 4; }
  else if (val.startsWith("La_sharp")) { idx = 5; }
  else if (val.startsWith("off")) { idx = -2; }
  else { idx = -2; }
  return idx;
}
