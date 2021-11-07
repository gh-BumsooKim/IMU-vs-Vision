#include <CapacitiveSensor.h>

CapacitiveSensor cs_C = CapacitiveSensor(12,11);  // C   
CapacitiveSensor cs_D = CapacitiveSensor(10,9);   // D 
CapacitiveSensor cs_E = CapacitiveSensor(8,7);    // E    
CapacitiveSensor cs_F = CapacitiveSensor(6,5);    // F    
CapacitiveSensor cs_G = CapacitiveSensor(4,3);    // G

int piano_set[5]; // activated or not

void setup() {
  Serial.begin(9600);
}

void loop() {

  int _C = cs_C.capacitiveSensor(30);
  int _D = cs_D.capacitiveSensor(30);
  int _E = cs_E.capacitiveSensor(30);
  int _F = cs_F.capacitiveSensor(30);
  int _G = cs_G.capacitiveSensor(30);

  // activated check
  piano_set[0] = (_C > 20 ? 1 : 0);
  piano_set[1] = (_D > 20 ? 1 : 0);
  piano_set[2] = (_E > 20 ? 1 : 0);
  piano_set[3] = (_F > 20 ? 1 : 0);
  piano_set[4] = (_G > 20 ? 1 : 0);

  // serial write
  for(int i=0; i<5; i++){
    // ASCII 67 = C, 68 = D, (omitted), 71 = G 
    Serial.write(i+67);
    
    // if 0, is not activated
    Serial.println(piano_set[i]);
  }
  
  delay(15); // for stability
}