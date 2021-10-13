// This example mimics traffic light
//
// while red 
// if input -> green(10s) -> yellow(2s)

int status;		// status : 0 is RED, 1 is GREEN and Yellow
int button;		// button input
int led_set[3];	// led output

//void turn_off(pin_array);

void setup(){
  // status variable
  status = 0;
  
  // button pin
  button = 7;
  
  // [Red, Green, Yellow]
  //led_set = {15, 16, 17};
    
  pinMode(button, INPUT_PULLUP);
  for(int i=0; i<3; i++){
    led_set[i] = 15 + i;
    pinMode(led_set[i], OUTPUT);
  }
}

void loop(){
  digitalWrite(led_set[0], HIGH);
  
  // detect button input
  if (digitalRead(button) == LOW){
    status = 1;
  }
  
  // main code to mimics a 'traffic light'
  if (status == 1){
    // wait 10s
    delay(10000);
    
    // turn on green led during 10s
    turn_off(led_set, sizeof(led_set)/sizeof(int));
    digitalWrite(led_set[1], HIGH);
    delay(10000);
    
    // turn on yellow led during 2s
    turn_off(led_set, sizeof(led_set)/sizeof(int));
    digitalWrite(led_set[2], HIGH);
    delay(2000);
    
    turn_off(led_set, sizeof(led_set)/sizeof(int));
    status = 0;
  }
}

// function : turn off all the LEDs 
void turn_off(int pin_array[], int size){
  for(int i=0; i<size; i++){
    digitalWrite(pin_array[i], LOW);
  }
}