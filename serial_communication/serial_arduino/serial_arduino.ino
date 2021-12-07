int input;

String scale_name[7] = {"Do_sharp", "Re_sharp", "Mi_sharp", "Fa_sharp", "Sol_sharp", "La_sharp", "Si_sharp"};

void setup() {
  //pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);

  pinMode(7, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
}

void loop() {
  input = -1;
  delay(50);

  if (digitalRead(7) == HIGH){ input = 0;}
  else if (digitalRead(6) == HIGH){ input = 1; }
  else if (digitalRead(5) == HIGH){ input = 3; }
  else if (digitalRead(4) == HIGH){ input = 4; }
  else if (digitalRead(3) == HIGH){ input = 5; }
  else { input = -1; }

  
  //Serial.println(input);
  // Send Message
  if (input >= 0){ Serial.println(scale_name[input]); }
  else { Serial.println("null"); }
}
