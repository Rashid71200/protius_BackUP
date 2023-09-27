float value;

int pwmOut = 3;  // The output to the transistor that drives the motor

void setup()
{
  Serial.begin(9600);
  Serial.println("value");
  pinMode(pwmOut, OUTPUT);  
}


void loop()                     
{
  analogWrite(pwmOut, 128); // about zero volts
  delay(50);
  Serial.print("pulseIn: ");
  Serial.println(pulseIn(5, HIGH));
  Serial.print("pulseIn: ");
  Serial.println(pulseIn(4, HIGH));
  Serial.println(' ');
  Serial.println(' ');
  delay(5000);

  analogWrite(pwmOut, 0); // about zero volts
  delay(50);
  Serial.print("pulseIn: ");
  Serial.println(pulseIn(5, HIGH));
  Serial.print("pulseIn: ");
  Serial.println(pulseIn(4, HIGH));
  Serial.println(' ');
  Serial.println(' ');
  delay(5000);




  analogWrite(pwmOut, 51); // about 1 volt
  delay(50);
  Serial.print("pulseIn: ");
  Serial.println(pulseIn(5, HIGH));
  Serial.print("pulseIn: ");
  Serial.println(pulseIn(4, HIGH));
  Serial.println(' ');
  Serial.println(' ');
  delay(5000);




  analogWrite(pwmOut, 102); // about 2 volts
  delay(50);
  Serial.print("pulseIn: ");
  Serial.println(pulseIn(5, HIGH));
  Serial.print("pulseIn: ");
  Serial.println(pulseIn(4, HIGH));
  Serial.println(' ');
  Serial.println(' ');
  delay(5000);




  analogWrite(pwmOut, 128); // about 2.5 volts
  delay(50);
  Serial.print("pulseIn: ");
  Serial.println(pulseIn(5, HIGH));
  Serial.print("pulseIn: ");
  Serial.println(pulseIn(4, HIGH));
  Serial.println(' ');
  Serial.println(' ');
  delay(5000);



  analogWrite(pwmOut, 153); // about 3.0 volts
  delay(50);
  Serial.print("pulseIn: ");
  Serial.println(pulseIn(5, HIGH));
  Serial.print("pulseIn: ");
  Serial.println(pulseIn(4, HIGH));
  Serial.println(' ');
  Serial.println(' ');
  delay(5000);



  analogWrite(pwmOut, 204); // about 4.0 volts
  delay(50);
  Serial.print("pulseIn: ");
  Serial.println(pulseIn(5, HIGH));
  Serial.print("pulseIn: ");
  Serial.println(pulseIn(4, HIGH));
  Serial.println(' ');
  Serial.println(' ');
  delay(5000);




  analogWrite(pwmOut, 255);  // about 5.0 volts
  delay(50);
  Serial.print("pulseIn: ");
  Serial.println(pulseIn(5, HIGH));
  Serial.print("pulseIn: ");
  Serial.println(pulseIn(4, HIGH));
  Serial.println(' ');
  Serial.println(' ');
  delay(5000);
}
