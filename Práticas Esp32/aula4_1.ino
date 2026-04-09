// Motor A
#define MOTOR_IN1   21
#define MOTOR_IN2   19
// Motor B
#define MOTOR_PWM   13


void setup() {
  // put your setup code here, to run once:
  pinMode(MOTOR_IN1, OUTPUT);
  pinMode(MOTOR_IN2, OUTPUT);
  pinMode(MOTOR_PWM, OUTPUT);
  Serial.begin(115200);
}

void motor_direction(int dir){
  if(dir == 1){
    Serial.println("frente");
    digitalWrite(MOTOR_IN1, HIGH);
    digitalWrite(MOTOR_IN2, LOW);
  }else if(dir == 2){
    Serial.println("tras");
    digitalWrite(MOTOR_IN1, LOW);
    digitalWrite(MOTOR_IN2, HIGH);
  }else if(dir == 3){
    Serial.println("parado");
    digitalWrite(MOTOR_IN1, LOW);
    digitalWrite(MOTOR_IN2, LOW);
  }
}
void motor_pwm(int pwm){
  Serial.println(pwm);
  analogWrite(MOTOR_PWM, pwm);
}
void loop() {
  motor_direction(1);
  motor_pwm(150);
  delay(500);
  motor_direction(2);
  motor_pwm(150);
  delay(500);
  motor_direction(2);
  motor_pwm(150);
  delay(500);
  // put your main code here, to run repeatedly:

}
