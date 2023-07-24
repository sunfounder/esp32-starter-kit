#define MOTOR_A_PIN_1A    14
#define MOTOR_A_PIN_1B    15
#define MOTOR_B_PIN_1A    13
#define MOTOR_B_PIN_1B    12

// use first channel of 16 channels (started from zero)
#define LEDC_CHANNEL_0     0
#define LEDC_CHANNEL_1     1                  
#define LEDC_CHANNEL_2     2
#define LEDC_CHANNEL_3     3


// use 8 bit precission for LEDC timer
#define LEDC_TIMER_12_BIT  8

// use 500 Hz as a LEDC base frequency
#define LEDC_BASE_FREQ     500

void setup() {
  // Setup timer and attach timer to a led pin
  ledcSetup(LEDC_CHANNEL_0, LEDC_BASE_FREQ, LEDC_TIMER_12_BIT);
  ledcSetup(LEDC_CHANNEL_1, LEDC_BASE_FREQ, LEDC_TIMER_12_BIT);
  ledcSetup(LEDC_CHANNEL_2, LEDC_BASE_FREQ, LEDC_TIMER_12_BIT);
  ledcSetup(LEDC_CHANNEL_3, LEDC_BASE_FREQ, LEDC_TIMER_12_BIT);      
  ledcAttachPin(MOTOR_A_PIN_1A, LEDC_CHANNEL_0);
  ledcAttachPin(MOTOR_A_PIN_1B, LEDC_CHANNEL_0);
  ledcAttachPin(MOTOR_B_PIN_1A, LEDC_CHANNEL_0);    
  ledcAttachPin(MOTOR_B_PIN_1B, LEDC_CHANNEL_0);

  // put your setup code here, to run once:
  Serial.begin(115200);

}


void loop() {
  for(int i=0;i<=255;i+=5){
    moveForward(i);
    delay(500);
  }
  for(int i=255;i>=0;i-=5){
    moveForward(i);
    delay(500);
  }
}

void moveForward(int speed) {
  Serial.println(speed);
  ledcWrite(LEDC_CHANNEL_0, 0);
  ledcWrite(LEDC_CHANNEL_1, speed);
  ledcWrite(LEDC_CHANNEL_2, speed);
  ledcWrite(LEDC_CHANNEL_3, 0);      
}


// #define B_1A 13
// #define B_1B 14

// // PWM settings
// const int freq = 5000; // PWM frequency: 5000 Hz
// const int resolution = 8; // PWM resolution: 8 bits
// const int channelA = 0; // PWM channel for B_1A: 0
// const int channelB = 1; // PWM channel for B_1B: 1


// void setup() {
//   // Set up PWM
//   ledcSetup(channelA, freq, resolution);
//   ledcSetup(channelB, freq, resolution);

//   // Attach PWM channels to GPIO pins
//   ledcAttachPin(B_1A, channelA);
//   ledcAttachPin(B_1B, channelB);

//   // put your setup code here, to run once:
//   Serial.begin(115200);  
// }

// void loop() {
//   // Increase speed gradually
//   for (int dutyCycle = 0; dutyCycle <= 255; dutyCycle++) {
//     Serial.println(dutyCycle);
//     ledcWrite(channelA, dutyCycle);
//     ledcWrite(channelB, 0);
//     delay(50);
//   }

//   delay(2000);

//   // Decrease speed gradually
//   for (int dutyCycle = 255; dutyCycle >= 0; dutyCycle--) {
//     Serial.println(dutyCycle);
//     ledcWrite(channelA, dutyCycle);
//     ledcWrite(channelB, 0);
//     delay(50);
//   }
  
//   delay(2000);
// }