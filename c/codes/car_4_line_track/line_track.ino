#define MOTOR_A_PIN_1A    13
#define MOTOR_A_PIN_1B    12
#define MOTOR_B_PIN_1A    14
#define MOTOR_B_PIN_1B    15

const int lineTrack = 2;

void setup() {
  Serial.begin(115200);

  //motor
  pinMode(MOTOR_A_PIN_1A, OUTPUT);
  pinMode(MOTOR_A_PIN_1B, OUTPUT);
  pinMode(MOTOR_B_PIN_1A, OUTPUT);
  pinMode(MOTOR_B_PIN_1B, OUTPUT);

  //ultrasonic
  pinMode(lineTrack, INPUT);
}

void loop() {
  int lineColor = digitalRead(lineTrack); // 0:white  1:black
  Serial.println(lineColor); //print on the serial monitor
  if (lineColor) {
    moveLeft();
  } else {
    moveRight();
  }
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
