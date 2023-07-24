#define MOTOR_A_PIN_1A    13
#define MOTOR_A_PIN_1B    12
#define MOTOR_B_PIN_1A    14
#define MOTOR_B_PIN_1B    15

const int rightIR = 36;
const int leftIR = 39;

void setup() {
  Serial.begin(115200);

  //motor
  pinMode(MOTOR_A_PIN_1A, OUTPUT);
  pinMode(MOTOR_A_PIN_1B, OUTPUT);
  pinMode(MOTOR_B_PIN_1A, OUTPUT);
  pinMode(MOTOR_B_PIN_1B, OUTPUT);

  //IR obstacle
  pinMode(leftIR,INPUT);
  pinMode(rightIR,INPUT);  
}

void loop() {
  int left = digitalRead(leftIR);  // 0: Obstructed   1: Empty
  int right = digitalRead(rightIR);
                                                            
  if (!left && right) {
    turnLeft();
  } else if (left && !right) {
    turnRight();
  } else {
    stopMove();
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
