#define MOTOR_A_PIN_1A    13
#define MOTOR_A_PIN_1B    12
#define MOTOR_B_PIN_1A    14
#define MOTOR_B_PIN_1B    15

void setup() {
  pinMode(MOTOR_A_PIN_1A, OUTPUT);
  pinMode(MOTOR_A_PIN_1B, OUTPUT);
  pinMode(MOTOR_B_PIN_1A, OUTPUT);
  pinMode(MOTOR_B_PIN_1B, OUTPUT);
}

void loop() {
  moveForward();
  delay(2000);
  stopMove();
  delay(500);

  moveBackward();
  delay(2000);
  stopMove();
  delay(500);

  turnLeft();
  delay(2000);
  stopMove();
  delay(500);

  turnRight();
  delay(2000);
  stopMove();
  delay(500);
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