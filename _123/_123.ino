// C++ code
int LED_BUILTIN1 = 8;
void setup()
{
  pinMode(LED_BUILTIN1, OUTPUT);
}

void loop()
{
  digitalWrite(LED_BUILTIN1, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(LED_BUILTIN1, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
}
