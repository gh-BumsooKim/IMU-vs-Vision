char input;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // sendData()
  Serial.println("Hello!");
  Serial.println("Bye~");
  delay(10);
}

void serialEvent(){
  // receiveData()
  while (Serial.available()){
    input = (char)Serial.read();
    
    if (input == '1'){
      digitalWrite(LED_BUILTIN, HIGH);
    }
    else{
      digitalWrite(LED_BUILTIN, LOW);
    }
  }
}
