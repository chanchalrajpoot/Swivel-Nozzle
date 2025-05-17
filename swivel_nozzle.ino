#include <Servo.h>
Servo sh1;
Servo sh2;
Servo sh3;
int L = 0;
int M = 0;
int N = 0;
int O = 0;
int P = 0;
int Q = 0;
unsigned long pwm;
void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  sh1.attach(8);
  sh2.attach(9);
  sh3.attach(10);
  setup_pwmRead();
}
void loop() {
  pwm = print_RCpwm();
  L = digitalRead(4);
  M = digitalRead(5);
  N = digitalRead(2);
  O = digitalRead(3);
  P = digitalRead(7);
  Q = digitalRead(6);
  /*Serial.print("limit 1 = ");
    Serial.println(L);
    Serial.print("limit 2 = ");
    Serial.println(M);
    Serial.print("limit 3 = ");
    Serial.println(N);
    Serial.print("limit 4 = ");
    Serial.println(O);
    Serial.print("limit 5 = ");
    Serial.println(P);
    Serial.print("limit 6 = ");
    Serial.println(Q);
    Serial.println(pwm);
    delay(500);*/
  if (pwm <= 156) {
    if (N == 1) {
      sh2.write(120);
      delay(10);
    }
    if (P == 1) {
      sh3.write(130);
      delay(10);
    }
    //N = digitalRead(4);
    //P = digitalRead(6);
    //sh2.write(90);
    //sh3.write(90);
    //pwm = print_RCpwm();
  }
  if (pwm >= 240) {
    if (O == 1) {
      sh2.write(50);
      delay(10);
    }
    if (Q == 1) {
      sh3.write(50);
      delay(10);
    }
    //O = digitalRead(5);
    //Q = digitalRead(7);
    //sh2.write(90);
    //sh3.write(90);
    //pwm = print_RCpwm();
  }
  Serial.println(pwm);
  sh2.write(90);
  sh3.write(90);
}
