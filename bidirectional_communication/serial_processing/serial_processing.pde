import processing.serial.*;

Serial myPort;
String val;

void setup(){
  size(300, 300);
  println(Serial.list());
  
  String portName = Serial.list()[0];
  myPort = new Serial(this, portName, 9600);
}

void draw(){
  // receiveData()
  if (myPort.available() > 0){
    val = myPort.readStringUntil('\n'); // receive from Arduino
    val = "Received message : " + val;
  }  
  println(val);
  
  // sendData()
  sendData();
}

void sendData(){
  if (mousePressed) {
    myPort.write('1'); // send a '1' to Arduino
    println("Sended message : 1");
  }
  else {
    myPort.write('0'); // send a '0' to Arduino
  }
}
