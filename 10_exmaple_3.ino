/*
 * Created by ArduinoGetStarted.com
 *
 * This example code is in the public domain
 *
 * Tutorial page: https://arduinogetstarted.com/faq/how-to-control-speed-of-servo-motor
 */

#include <Servo.h>

#define PIN_SERVO 10

Servo myServo;
unsigned long MOVING_TIME = 6000; // moving time is 3 seconds
unsigned long moveStartTime;
int startAngle = 26; // 30°
int stopAngle  = 86; // 90°

double sigmoid(double x) {
  return 1.0 / ( 1.0 + exp(-x));
}

void setup() {
  myServo.attach(PIN_SERVO);
  moveStartTime = millis(); // start moving

  myServo.write(startAngle); // Set position
  delay(500);
}

void loop() {
  unsigned long progress = millis() - moveStartTime;

  if (progress <= MOVING_TIME) {
    long angle = map(progress, 0, MOVING_TIME, startAngle-56, stopAngle-56);
    angle = sigmoid(0.2 * angle) * (stopAngle - startAngle) + startAngle;
    myServo.write(angle); 
  }
}
