//sw1 fnd 1 홀수 upcount, led 1 / 손때면 동작 멈추고 소등
//sw2 fnd 2 짝수 upcount, led 2 / //
//sw3 fnd 99 홀수 downcount led3 / //
//sw4 fnd 98 짝수 downcount led 4 / //

#include <Arduino.h>

void setup() {
  for(int i=2; i<=9; i++){
    pinMode(i, OUTPUT);
  }
  for(int i=10; i<=13; i++){
    pinMode(i, INPUT);
  }
  for(int i=14; i<=17; i++){
    pinMode(i, OUTPUT);
  }
  for(int i=18; i<=19; i++){
    pinMode(i,OUTPUT);
  }
  Serial.begin(9600);
}

int fnd_num[10][4]{
  {0,0,0,0},{1,0,0,0},
  {0,1,0,0},{1,1,0,0},
  {0,0,1,0},{1,0,1,0},
  {0,1,1,0},{1,1,1,0},
  {0,0,0,1},{1,0,0,1}
};

void display_num(int num){
  int ten = num/10;
  int one = num%10;

  for(int i=0; i<50; i++){ //10의 자리
    digitalWrite(18, 1);
    digitalWrite(19, 0);
    digitalWrite(14, fnd_num[ten][0]);
    digitalWrite(15, fnd_num[ten][1]);
    digitalWrite(16, fnd_num[ten][2]);
    digitalWrite(17, fnd_num[ten][3]);
    delay(5);

    digitalWrite(18, 0); //1의자리
    digitalWrite(19, 1);
    digitalWrite(14, fnd_num[one][0]);
    digitalWrite(15, fnd_num[one][1]);
    digitalWrite(16, fnd_num[one][2]);
    digitalWrite(17, fnd_num[one][3]);
    delay(5);
  }
}
  int buttonstate01 = 1;
  int buttonstate02 = 1;
  int buttonstate03 = 1;
  int buttonstate04 = 1;
  int lastbuttonstate01 = 1;
  int lastbuttonstate02 = 1;
  int lastbuttonstate03 = 1;
  int lastbuttonstate04 = 1;
  
  int count;
  int count1 = 1;
  int count2 = 0;
  int count3 = 99;
  int count4 = 98;

void loop() {
  buttonstate01 = digitalRead(10);
  buttonstate02 = digitalRead(11);
  buttonstate03 = digitalRead(12);
  buttonstate04 = digitalRead(13);

  //sw1을 누르고 있으면 홀수업카운트. led점등
  //sw에서 손 떼면 카운트 멈춤. led소등
  if(buttonstate01==lastbuttonstate01 && buttonstate01 == LOW){
    digitalWrite(2, 1);
    digitalWrite(3, 0);
    digitalWrite(4, 0);
    digitalWrite(5, 0);
    digitalWrite(6, 0);
    digitalWrite(7, 0);
    digitalWrite(8, 0);
    digitalWrite(9, 0);

    Serial.println(count1);
    display_num(count);
    count = count1;
    count1 = count1+2;
    if(count1>99) count1=1;
  }
  if(buttonstate02==lastbuttonstate02 && buttonstate02 == LOW){
    digitalWrite(2, 0);
    digitalWrite(3, 1);
    digitalWrite(4, 0);
    digitalWrite(5, 0);
    digitalWrite(6, 0);
    digitalWrite(7, 0);
    digitalWrite(8, 0);
    digitalWrite(9, 0);

    Serial.println(count2);
    display_num(count);
    count = count2;
    count2 = count2+2;
    if(count2>98) count2=0;
  } 
  if(buttonstate03==lastbuttonstate03 && buttonstate03 == LOW){
    digitalWrite(2, 0);
    digitalWrite(3, 0);
    digitalWrite(4, 1);
    digitalWrite(5, 0);
    digitalWrite(6, 0);
    digitalWrite(7, 0);
    digitalWrite(8, 0);
    digitalWrite(9, 0);

    Serial.println(count3);
    display_num(count);
    count = count3;
    count3 = count3-2;
    if(count3<1) count3=99;
  } 
  if(buttonstate04==lastbuttonstate04 && buttonstate04 == LOW){
    digitalWrite(2, 0);
    digitalWrite(3, 0);
    digitalWrite(4, 0);
    digitalWrite(5, 1);
    digitalWrite(6, 0);
    digitalWrite(7, 0);
    digitalWrite(8, 0);
    digitalWrite(9, 0);

    Serial.println(count4);
    display_num(count);
    count = count4;
    count4 = count4-2;
    if(count4<0) count4=98;
  }

    display_num(count);
    digitalWrite(2, 0);
    digitalWrite(3, 0);
    digitalWrite(4, 0);
    digitalWrite(5, 0);

  lastbuttonstate01 = buttonstate01;
  lastbuttonstate02 = buttonstate02;
  lastbuttonstate03 = buttonstate03;
  lastbuttonstate04 = buttonstate04;
}