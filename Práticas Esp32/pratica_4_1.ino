// Motor A
#define MOTOR_IN1   21
#define MOTOR_IN2   19
// Motor B
#define MOTOR_PWM   13
#define BUTTON 12


void setup() {
  // put your setup code here, to run once:
  pinMode(MOTOR_IN1, OUTPUT);
  pinMode(MOTOR_IN2, OUTPUT);
  pinMode(MOTOR_PWM, OUTPUT);
  pinMode(BUTTON, INPUT_PULLUP);
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

int timer = 500;
unsigned long last_time;
bool Button_state;
bool Button_pressed;
bool State_motor;
void loop() {
  unsigned long now = millis();
  bool state = !digitalRead(BUTTON);

  //Botão Sincrono
  if(state && !Button_state){
    Button_pressed = !Button_pressed;
    Button_state = true;
    State_motor = !State_motor;
  }
  if(!state){
    Button_state = false;
  }

  //MOTOR

  if(State_motor){
    motor_direction(1);
    motor_pwm(150);
  }else{
    motor_direction(2);
    motor_pwm(150);
  }
  
  delay(10);
}
