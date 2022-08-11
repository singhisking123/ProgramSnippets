
void setup()
{
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
}

void loop()
{
    analogWrite(1, 255);
    analogWrite(2, 0);
    analogWrite(3, 0);
}