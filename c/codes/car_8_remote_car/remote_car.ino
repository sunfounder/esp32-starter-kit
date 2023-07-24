#define MOTOR_A_PIN_1A    13
#define MOTOR_A_PIN_1B    12
#define MOTOR_B_PIN_1A    14
#define MOTOR_B_PIN_1B    15

#include <IRrecv.h>

// 定义IR接收器引脚
const uint16_t IR_RECEIVE_PIN = 23;

// 创建一个IRrecv对象
IRrecv irrecv(IR_RECEIVE_PIN);

// 创建一个decode_results对象
decode_results results;

void setup() {
  // 启动串口
  Serial.begin(115200);

  // 启动IR接收器
  irrecv.enableIRIn();

  pinMode(MOTOR_A_PIN_1A, OUTPUT);
  pinMode(MOTOR_A_PIN_1B, OUTPUT);
  pinMode(MOTOR_B_PIN_1A, OUTPUT);
  pinMode(MOTOR_B_PIN_1B, OUTPUT);
}

void loop() {
  // 如果接收到了红外信号
  if (irrecv.decode(&results)) {
    String key = decodeKeyValue(results.value);
    if (key != "ERROR") {
      // 将信号的数值输出到串口
      Serial.println(key);
      if (key == "2") {
        moveForward();
        delay(1000);
      } else if (key == "4") {
        turnLeft();
      } else if (key == "6") {
        turnRight();
      } else if (key == "8") {
        moveBackward();
        delay(1000);
      }else if (key == "1") {
        moveLeft();
      }else if (key == "3") {
        moveRight();
      }else if (key == "7") {
        backLeft();
      }else if (key == "9") {
        backRight();
      }
      delay(500);
      stopMove();
    }
    // 重新启动IR接收器以接收下一个信号
    irrecv.resume();
  }
}


void moveForward() {
  digitalWrite(MOTOR_A_PIN_1A, LOW);
  digitalWrite(MOTOR_A_PIN_1B, HIGH);
  digitalWrite(MOTOR_B_PIN_1A, HIGH);
  digitalWrite(MOTOR_B_PIN_1B, LOW);
}

void moveBackward() {
  digitalWrite(MOTOR_A_PIN_1A, HIGH);
  digitalWrite(MOTOR_A_PIN_1B, LOW);
  digitalWrite(MOTOR_B_PIN_1A, LOW);
  digitalWrite(MOTOR_B_PIN_1B, HIGH);
}

void turnRight() {
  digitalWrite(MOTOR_A_PIN_1A, HIGH);
  digitalWrite(MOTOR_A_PIN_1B, LOW);
  digitalWrite(MOTOR_B_PIN_1A, HIGH);
  digitalWrite(MOTOR_B_PIN_1B, LOW);
}

void turnLeft() {
  digitalWrite(MOTOR_A_PIN_1A, LOW);
  digitalWrite(MOTOR_A_PIN_1B, HIGH);
  digitalWrite(MOTOR_B_PIN_1A, LOW);
  digitalWrite(MOTOR_B_PIN_1B, HIGH);
}

void stopMove() {
  digitalWrite(MOTOR_A_PIN_1A, LOW);
  digitalWrite(MOTOR_A_PIN_1B, LOW);
  digitalWrite(MOTOR_B_PIN_1A, LOW);
  digitalWrite(MOTOR_B_PIN_1B, LOW);
}

void moveLeft() {
  digitalWrite(MOTOR_A_PIN_1A, LOW);
  digitalWrite(MOTOR_A_PIN_1B, HIGH);
  digitalWrite(MOTOR_B_PIN_1A, LOW);
  digitalWrite(MOTOR_B_PIN_1B, LOW);
}

void moveRight() {
  digitalWrite(MOTOR_A_PIN_1A, LOW);
  digitalWrite(MOTOR_A_PIN_1B, LOW);
  digitalWrite(MOTOR_B_PIN_1A, HIGH);
  digitalWrite(MOTOR_B_PIN_1B, LOW);
}

void backLeft() {
  digitalWrite(MOTOR_A_PIN_1A, HIGH);
  digitalWrite(MOTOR_A_PIN_1B, LOW);
  digitalWrite(MOTOR_B_PIN_1A, LOW);
  digitalWrite(MOTOR_B_PIN_1B, LOW);
}

void backRight() {
  digitalWrite(MOTOR_A_PIN_1A, LOW);
  digitalWrite(MOTOR_A_PIN_1B, LOW);
  digitalWrite(MOTOR_B_PIN_1A, LOW);
  digitalWrite(MOTOR_B_PIN_1B, HIGH);
}