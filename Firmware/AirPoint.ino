#include <BleMouse.h>
#include <Wire.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>

// Button pins
#define LEFT_BUTTON 19
#define RIGHT_BUTTON 18
#define SCROLL_UP_BUTTON 5
#define SCROLL_DOWN_BUTTON 17

// BLE Mouse
BleMouse bleMouse("AirPoint", "Sudip", 100);

// MPU6050
Adafruit_MPU6050 mpu;

// Sensitivity (Y is higher)
float sensitivityX = 3.5;
float sensitivityY = 7.5;

// Dead zone
float deadZone = 0.01;

// Smoothing
float smoothX = 0, smoothY = 0;
float alpha = 0.3;

unsigned long lastKeepAlive = 0;

void setup() {
  Serial.begin(115200);

  pinMode(LEFT_BUTTON, INPUT_PULLUP);
  pinMode(RIGHT_BUTTON, INPUT_PULLUP);
  pinMode(SCROLL_UP_BUTTON, INPUT_PULLUP);
  pinMode(SCROLL_DOWN_BUTTON, INPUT_PULLUP);

  Wire.begin(21, 22);

  if (!mpu.begin()) {
    Serial.println("MPU6050 not found!");
    while (1);
  }

  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);

  bleMouse.begin();
  delay(2000);
}

void loop() {
  if (bleMouse.isConnected()) {

    sensors_event_t a, g, temp;
    mpu.getEvent(&a, &g, &temp);

    // Raw gyro movement
    float rawX = g.gyro.y * sensitivityX;
    float rawY = -g.gyro.x * sensitivityY;

    // Dead zone
    if (abs(rawX) < deadZone) rawX = 0;
    if (abs(rawY) < deadZone) rawY = 0;

    // Smoothing
    smoothX = (alpha * rawX) + ((1 - alpha) * smoothX);
    smoothY = (alpha * rawY) + ((1 - alpha) * smoothY);

    int moveX = (int)smoothX;
    int moveY = (int)smoothY;

    // Minimum movement (Windows fix)
    if (moveX != 0) moveX = (moveX > 0) ? max(1, moveX) : min(-1, moveX);
    if (moveY != 0) moveY = (moveY > 0) ? max(1, moveY) : min(-1, moveY);

    // Move or keep alive
    if (moveX == 0 && moveY == 0) {
      bleMouse.move(0, 0);
    } else {
      bleMouse.move(moveX, moveY);
    }

    // LEFT CLICK
    if (digitalRead(LEFT_BUTTON) == LOW) {
      bleMouse.press(MOUSE_LEFT);
    } else {
      bleMouse.release(MOUSE_LEFT);
    }

    // RIGHT CLICK
    if (digitalRead(RIGHT_BUTTON) == LOW) {
      bleMouse.press(MOUSE_RIGHT);
    } else {
      bleMouse.release(MOUSE_RIGHT);
    }

    // SCROLL UP
    if (digitalRead(SCROLL_UP_BUTTON) == LOW) {
      bleMouse.move(0, 0, 1);
      delay(80);
    }

    // SCROLL DOWN
    if (digitalRead(SCROLL_DOWN_BUTTON) == LOW) {
      bleMouse.move(0, 0, -1);
      delay(80);
    }

    // Keep-alive
    if (millis() - lastKeepAlive > 1000) {
      bleMouse.move(0, 0);
      lastKeepAlive = millis();
    }

    delay(5);
  }
}