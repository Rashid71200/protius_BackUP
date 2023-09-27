int analog_pin = 9; // Change to the desired analog pin number

void setup() {
  pinMode(analog_pin, OUTPUT);
}

void loop() {
  // Generate a random PWM value between 10 and 255
  int pwmValue = random(10, 256); // Random value between 10 and 255
  analogWrite(analog_pin, pwmValue);
  delay(100);
}
