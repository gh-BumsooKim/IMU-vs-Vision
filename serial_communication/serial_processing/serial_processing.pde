import processing.serial.*;

void setup(){  
  //println(Serial.list());
  
  String portName = Serial.list()[0];
  myPort = new Serial(this, portName, 9600);
  
  size(640, 320);
  strokeWeight(1);
        
  // Piano Drawing
  drawPiano();
  
  // Piano Sound
  osc = new SinOsc(this);
}

void draw(){
  idx = -2;
  if (idx == -2){ osc.stop(); }
  drawPiano();
  
  // Receive Message
  if (myPort.available() > 0){
    val = myPort.readStringUntil('\n'); // receive from Arduino
  }
  
  // Main Code for Piano
  if (val != null){
    idx = whichPressed(val);
    
    // Debug
    if (val.startsWith("null") != true) { println(val); }
    
    playPiano(idx);
  }
}
