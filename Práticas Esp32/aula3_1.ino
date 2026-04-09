#define led_pin 32

#define sensor_pin 34
void setup() {
  pinMode(led_pin, OUTPUT);
  pinMode(sensor_pin, INPUT);
  Serial.begin(115200);
}


int delta = 3500;
void loop() {
  int sensor_value = analogRead(sensor_pin);
  Serial.println(sensor_value);
  if(sensor_value >= delta){
    Serial.print("ligado");
    digitalWrite(led_pin, HIGH);
  }else{
    digitalWrite(led_pin, LOW);
  }
  delay(10);
}
