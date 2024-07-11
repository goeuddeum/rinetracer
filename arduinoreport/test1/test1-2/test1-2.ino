#include <LiquidCrystal_I2C.h>
#include <Wire.h>

// 모터 핀 설정
#define IN1 10
#define IN2 12
#define IN3 11
#define IN4 13

// 적외선 센서 핀 설정
#define LS 6
#define RS 7

#define THRESHOLD 200

void setup() {
  Serial.begin(9600);

  // 모터 핀을 출력으로 설정
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // 적외선 센서 핀을 입력으로 설정 (아날로그 핀은 pinMode 설정이 필요 없음)
}

void STOP() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, HIGH);
  
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, HIGH);
}

void FWD() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void LT() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void RT() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}


void loop() {
  int LSval = analogRead(LS);
  int RSval = analogRead(RS);

  Serial.print("LS:RS= ");
  Serial.print(LSval);
  Serial.print(":");
  Serial.print(RSval); 
  Serial.println(":");
  delay(10);

  if (LSval > THRESHOLD && RSval > THRESHOLD) FWD();
  else if (LSval < THRESHOLD && RSval > THRESHOLD) LT();
  else if (LSval > THRESHOLD && RSval < THRESHOLD) RT();
  else if (LSval < THRESHOLD && RSval < THRESHOLD) STOP();
}
