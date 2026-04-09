void setup() {
  pinMode(22, INPUT_PULLUP);
  pinMode(23, OUTPUT);
  
  Serial.begin(115200);
}

int timer = 500;
unsigned long last_time;
bool Button_state;
bool Button_pressed;
bool state;

void loop() {
  unsigned long now = millis();
  //bool state = !digitalRead(22);
  
  int touchValue = touchRead(32); // Lê o pino T0 (GPI32)
  //Serial.println(touchValue);
  
  if(touchValue > 500){
      state = false;
    }else{
      state = true;
    }
  //Serial
  if(Serial.available() > 0) {
        int incomingByte = Serial.parseInt();
        if(incomingByte > 0){
          Serial.print("Eu recebi: ");
          timer = (incomingByte);
          Serial.println(timer);
        }
    }
  
  //Botão Sincrono
  if(state && !Button_state){
    Button_pressed = !Button_pressed;
    Button_state = true;
  }
  if(!state){
    Button_state = false;
  }

  //LED
  if(Button_pressed){
    if(now - last_time <= timer/2){
    digitalWrite(23, HIGH);
    }else if(now - last_time <= timer){
      digitalWrite(23, LOW);
    }else{
      last_time = now;
    }
  }else{
    digitalWrite(23, LOW);
  }    
  delay(10);
}
