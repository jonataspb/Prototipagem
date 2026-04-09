#define led_pin 32
#define led_pin_2 26

#define sensor_pin 34
void setup() {
  pinMode(led_pin, OUTPUT);
  pinMode(led_pin_2, OUTPUT);
  pinMode(sensor_pin, INPUT);
  Serial.begin(115200);
}


void loop() {
  float sensor_value = analogRead(sensor_pin)*0.062;
  Serial.println(sensor_value);
  analogWrite(led_pin, sensor_value);
  dacWrite(led_pin_2, sensor_value);
  delay(10);
}
