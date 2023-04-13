void setup() { 
   for (int i = 2; i < 6; i++) {
     pinMode(i, OUTPUT);
   }
}

void clockwise(int num)
{
  for (int count = 0; count < num; count++)
  {
    for (int i = 2; i < 6; i++)
    {
      digitalWrite(i, HIGH);
      delay(3);
      digitalWrite(i, LOW);
    }
  }
}

void anticlockwise(int num)
{
  for (int count = 0; count < num; count++)
  {
    for (int i = 5; i > 1; i--)
    {
      digitalWrite(i, HIGH);
      delay(3);
      digitalWrite(i, LOW);
    }
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  clockwise(256);//512 for one circle
  delay(10);
  anticlockwise(256);
}
