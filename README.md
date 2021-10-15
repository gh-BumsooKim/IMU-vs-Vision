# Arduino-Artwork
This repository is the Robotic Artwork using "Arduino" , "3D modeling", and Interaction sensor.

## Pre-Application

**Pixel Game Release v1.0.0 to be Annouced**

## Examples

```ino
digitalWrite(RED_PIN, HIGH);

// detect button input
if (digitalRead(BUTTON) == LOW){ status = 1; }

// main code to mimics a 'traffic light'
if (status == 1){
  // turn on green led during 1s
  turn_off(LED_PIN_SET);
  digitalWrite(GREEN_PIN, HIGH); }
```

<p align="center">
  <img src="example/traffic_light.png">
</p>
