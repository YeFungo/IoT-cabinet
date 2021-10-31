#include <Servo.h>

Servo myservo;
// 스위치를 5번 핀으로 설정합니다.
int sw = 5;
// 서보모터의 회전 각도입니다.
int angle = 0;

// 기계적인 스위치를 누르게 되면 전극판이 완전히 밀착되기 전까지,
// 매우 짧은 시간 동안 불안정한 신호를 발생시키며, 여러번 누른 것과 같은 현상이 나타납니다.
// 이를 바운스 현상아라하며, 이를 방지하기 위하여 일정시간동안은 이러한 불안정한 신호를 고려하지 않습니다.
// 이러한 방법을 디바운스라 합니다.
// 바운스 시작 시간을 초기화합니다.
long bounceStartTime = 0;
// 본 예제에서는 스위치를 눌렀을때 50ms 안의 신호는 바운스 현상으로 간주하고, 디바운스 합니다.
long debounce = 50;

// 실행시 가장 먼저 호출되는 함수이며, 최초 1회만 실행됩니다.
// 변수를 선언하거나 초기화를 위한 코드를 포함합니다.
void setup() {
  // 서보모터를 A3핀으로 설정합니다.
  myservo.attach(A3);
  // 스위치가 연결된 핀의 모드를 INPUT_PULLUP 상태(초기 로직레벨을 HIGH로 설정)로 설정합니다.
  // 설정된 디지털 핀은 아래와 같은 값을 반환합니다.
  // 스위치가 열려있다면 (누르지 않은 상태) HIGH
  // 스위치를 닫혀있다면 (누른 상태), LOW
  pinMode(sw, INPUT_PULLUP);
}

// setup() 함수가 호출된 이후, loop() 함수가 호출되며,
// 블록 안의 코드를 무한히 반복 실행됩니다.
void loop() {
  // 스위치가 연결된 핀의 로직레벨이 LOW라면,
  // 스위치가 닫혀있는 상태(누른 상태) 이므로, 아래의 블록을 실행합니다.
  if (digitalRead(sw) == LOW)
  {
    angle = 90;
    myservo.write(angle);
    delay(1000);
  }
 if (digitalRead(sw) == HIGH)
 {
      angle = 180;
      myservo.write(angle);
      delay(1000);
 }
}
