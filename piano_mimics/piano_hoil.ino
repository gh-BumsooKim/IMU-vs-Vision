#include <CapacitiveSensor.h>

CapacitiveSensor cs_C = CapacitiveSensor(8,2);  
CapacitiveSensor cs_D = CapacitiveSensor(8,3); 
CapacitiveSensor cs_F = CapacitiveSensor(8,4);
CapacitiveSensor cs_G = CapacitiveSensor(9,5);
CapacitiveSensor cs_A = CapacitiveSensor(9,6);

String piano_name[] = {"Do", "Re", "Fa", "Sol", "La"};
int piano_set[5];

void setup()
{
  Serial.begin(115200);

  for (int i=0; i<5; i++) { pinMode(i+3, INPUT_PULLUP); } // Digital Pin7 ~ Pin3
  pinMode(13, OUTPUT);
}

void loop()
{
  readPiano();  
  playPiano();

  delay(30);
}

void readPiano(){
  int _C = cs_C.capacitiveSensor(30);
  int _D = cs_D.capacitiveSensor(30);
  int _F = cs_F.capacitiveSensor(30);
  int _G = cs_G.capacitiveSensor(30);
  int _A = cs_A.capacitiveSensor(30);

  piano_set[0] = (_C > 20 ? 1 : 0);
  piano_set[1] = (_D > 20 ? 1 : 0);
  piano_set[2] = (_F > 20 ? 1 : 0);
  piano_set[3] = (_G > 20 ? 1 : 0);
  piano_set[4] = (_A > 20 ? 1 : 0);
}

void playPiano(){
  for (int i=0; i<5; i++) {
    if (piano_set[i] == true){
      Serial.println(piano_name[i] + "_Sharp");
      tone(13, 277 + i*19, 200); // CS = 277 Hz ... (omitted)
    }
  }
}
