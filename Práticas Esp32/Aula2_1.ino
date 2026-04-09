void setup() {
  pinMode(22, INPUT_PULLUP);
  pinMode(23, OUTPUT);
  Serial.begin(115200);
}

int timer = 500;
unsigned long last_time;
bool Button_state;
bool Button_pressed;

void loop() {
  unsigned long now = millis();
  bool state = !digitalRead(22);
  
  //Serial
  if(Serial.available() > 0) {
        int incomingByte = Serial.read();
        if(incomingByte != 10){
          Serial.print("Eu recebi: ");
          timer = (incomingByte-48)*50;
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
