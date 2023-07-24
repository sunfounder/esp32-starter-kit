#define MOTOR_A_PIN_1A    13
#define MOTOR_A_PIN_1B    12
#define MOTOR_B_PIN_1A    14
#define MOTOR_B_PIN_1B    15

const int trigPin = 22;
const int echoPin = 23;

void setup() {
  Serial.begin(115200);

  //motor
  pinMode(MOTOR_A_PIN_1A, OUTPUT);
  pinMode(MOTOR_A_PIN_1B, OUTPUT);
  pinMode(MOTOR_B_PIN_1A, OUTPUT);
  pinMode(MOTOR_B_PIN_1B, OUTPUT);

  //ultrasonic
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
}

void loop() {
  float distance = readSensorData();
  if (distance > 25) {
    moveForward();
  }
  else if (distance < 10 && distance > 2) {
    moveBackward();
  } else {
    stopMove();
  }
}

float readSensorData() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  float distance = pulseIn(echoPin, HIGH) / 58.00; //Equivalent to (340m/s*1us)/2
  return distance;
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
