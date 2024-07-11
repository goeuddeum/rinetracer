#include <LiquidCrystal_I2C.h>
#include <Wire.h>

// 모터 핀 설정
#define IN1 10
#define IN2 12

#define IN3 11
#define IN4 13

const int trigPin = 4;
const int echoPin = 5;

// 적외선 센서 핀 설정
#define LS 6
#define RS 7

void setup() {
  Serial.begin(9600);

  // 모터 핀을 출력으로 설정
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // 적외선 센서 핀을 입력으로 설정
  pinMode(LS, INPUT);
  pinMode(RS, INPUT);
}

void STOP(){
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, HIGH);
  
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, HIGH);
}

void FWD(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void LT(){
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void RT(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void BWD(){
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void loop() {
  long duration, cm_distance;

  // 초음파 센서 트리거 신호
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);

  // 거리 계산
  cm_distance = duration / 29 / 2;
  
  if (cm_distance <= 10) { 
    STOP();  
    delay(500);
    BWD();
    delay(500);
    LT();
    delay(900);
    FWD();
    delay(500);
  } else {
    FWD();  
  }
  delay(100);  
}
