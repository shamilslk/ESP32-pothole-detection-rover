#include <Servo.h>

Servo servoMotor;

#define ENA 5
#define IN1 8
#define IN2 7
#define ENB 11
#define IN3 4
#define IN4 3

#define SERVO_PIN 6
#define TRIG_PIN 9
#define ECHO_PIN 2
#define RELAY_PIN 12

int pulse = 1500;
int direction = 1;

unsigned long lastMove = 0;
unsigned long lastMeasure = 0;

int moveInterval = 10;
int stepSize = 20;
int measureInterval = 100;

int potholeThreshold = 5;

bool moving = false;
bool potholeDetected = false;

char aiCommand = 'N';

void moveForwardSmooth() {

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  if(!moving) {

    analogWrite(ENA,150);
    analogWrite(ENB,150);
    delay(50);

    analogWrite(ENA,80);
    analogWrite(ENB,80);
    delay(200);

    moving = true;
  }

  analogWrite(ENA,55);
  analogWrite(ENB,55);
}

void stopRover() {

  analogWrite(ENA,0);
  analogWrite(ENB,0);

  moving = false;
}

void turnLeft() {

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  analogWrite(ENA,60);
  analogWrite(ENB,60);
}

void turnRight() {

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  analogWrite(ENA,60);
  analogWrite(ENB,60);
}

int getDistance() {

  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH, 25000);

  if(duration == 0)
    return -1;

  return duration * 0.034 / 2;
}

void fillPothole() {

  Serial.println("FILLING START");

  digitalWrite(RELAY_PIN,HIGH);

  delay(5000);

  digitalWrite(RELAY_PIN,LOW);

  Serial.println("FILLING DONE");
}

void setup() {

  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(RELAY_PIN,OUTPUT);

  servoMotor.attach(SERVO_PIN);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  Serial.begin(9600);

  moveForwardSmooth();
}

void loop() {

  /* -----------------------------
     Receive AI command
  ------------------------------*/

  if(Serial.available()) {

    aiCommand = Serial.read();

  }

  /* -----------------------------
     AI Alignment
  ------------------------------*/

  if(aiCommand == 'L') {

    turnLeft();
    return;

  }

  if(aiCommand == 'R') {

    turnRight();
    return;

  }

  if(aiCommand == 'C') {

    moveForwardSmooth();

  }

  /* -----------------------------
     Servo scanning
  ------------------------------*/

  if(!potholeDetected && millis() - lastMove >= moveInterval) {

    pulse += direction * stepSize;

    if(pulse >= 2100 || pulse <= 900)
      direction *= -1;

    servoMotor.writeMicroseconds(pulse);

    lastMove = millis();
  }

  /* -----------------------------
     Ultrasonic check
  ------------------------------*/

  if(millis() - lastMeasure >= measureInterval) {

    int d1 = getDistance();
    delay(5);
    int d2 = getDistance();
    delay(5);
    int d3 = getDistance();

    int dist = (d1 + d2 + d3) / 3;

    int angle = map(pulse,900,2100,0,180);

    Serial.print("Angle: ");
    Serial.print(angle);
    Serial.print(" Distance: ");
    Serial.println(dist);

    if(dist > potholeThreshold && dist != -1) {

      potholeDetected = true;

      stopRover();

      Serial.println("POTHOLE CONFIRMED");

      fillPothole();

      potholeDetected = false;

      moveForwardSmooth();
    }

    lastMeasure = millis();
  }
}
