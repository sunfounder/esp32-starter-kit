#define MOTOR_A_PIN_1A    13
#define MOTOR_A_PIN_1B    12
#define MOTOR_B_PIN_1A    14
#define MOTOR_B_PIN_1B    15

const int trigPin = 22;
const int echoPin = 23;

const int rightIR = 36;
const int leftIR = 39;

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

  //IR obstacle
  pinMode(leftIR,INPUT);
  pinMode(rightIR,INPUT);  
}

void loop() {
  float distance = readSensorData();

  int left = digitalRead(leftIR);  // 0: Obstructed   1: Empty
  int right = digitalRead(rightIR);

  if (distance>5 && distance<10){
    moveForward();
  }
  else if(!left&&right){
    turnLeft();
  }else if(left&&!right){
    turnRight();
  }else{
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
