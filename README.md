# IMU vs Vision

## This gif shows Project Prototype! using 1 IMU Sensor.

<p align="center">
  <img src="imgs/prototype.gif"><br>
  Title : <b>IMU Sensor</b> versus <b>Vision Algorithm</b> for Hands-Gesture Recognition
</p>



## Implementation

- Arduino Nano, Arduino Uno
- Raspberrt Pi 4B
- IMU, LED Dot Matrix, Webcam

## IMU Part

- IMU Data Processing Diagram

![image](https://user-images.githubusercontent.com/67869508/143436016-10103eea-8b2e-45d1-be06-7d9a310a604b.png)


- IMU Data Class Annotation

![image](https://user-images.githubusercontent.com/67869508/143076283-6f137ca6-219a-4226-95b3-ff5b8859ab5f.png)



<!--
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
/--> 
