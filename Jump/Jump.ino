#include<Servo.h>

Servo myServo;
int pos = 0;


int char_to_int(char i)
{
  switch(i)
  {
    case '0':return 0;
    case '1':return 1;
    case '2':return 2;
    case '3':return 3;
    case '4':return 4;
    case '5':return 5;
    case '6':return 6;
    case '7':return 7;
    case '8':return 8;
    case '9':return 9;
    default:return 0;
  }
}
void setup()
{
  Serial.begin(9600);
    myServo.attach(9);
    myServo.write(0);   //初始化舵机转动角度
    delay(2000);
}

void loop()
{
  char a, b, c, d;   //  个十百千
  int s;
  while(!Serial.available());
  if(Serial.available())
  {
    a = Serial.read();
    delay(5);
  }
  if(Serial.available())
  {
    b = Serial.read();
    delay(5);
  }
  if(Serial.available())
  {
    c = Serial.read();
    delay(5);
  }
  if(Serial.available())
  {
    d = Serial.read();
    delay(5);
  }
  if(b == NULL)
  {
    s = char_to_int(a);
    Serial.println(s, DEC);
  }
  else if(c == NULL)
  {
    s = char_to_int(a) * 10 + char_to_int(b);
    Serial.println(s, DEC);
  }
  else if(d == NULL)
  {
    s = char_to_int(a) * 100 + char_to_int(b) * 10 + char_to_int(c);
    Serial.println(s, DEC);
  }
  else
  {
    s = char_to_int(a) * 1000 + char_to_int(b) * 100 + char_to_int(c) * 10 + char_to_int(d);
    Serial.println(s, DEC);
  }
//  else if(b != NULL && c != NULL && d != NULL)
//  {
//    s = char_to_int(a) * 1000 + char_to_int(b) * 100 + char_to_int(c) * 10 + char_to_int(d);
//    Serial.println(s, DEC);
//  }
  //s = s * 23;
    for(int pos = 0; pos <= 30; pos ++)
    {
        myServo.write(pos);
        delay(15);
    }
    delay(s);  //  与触屏接触的时间/ms

    for(int pos = 30; pos >= 0; pos --)
    {
        myServo.write(pos);
        delay(15);
    }
}
