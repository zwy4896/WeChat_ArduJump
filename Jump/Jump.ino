#include<Servo.h>

Servo myServo;

int pos_ini = 90;  //init servo

int tt;   //   time of touch
char inByte = 0;   // recieved data
String temp = "";   //cache, maybe

void setup()
{
	//  open the door! little boy! init servo
	Serial.begin(9600);
    myServo.attach(9);
    myServo.write(pos_ini);
    delay(1000);
}

void loop()
{
	while (!Serial.available());
	while (Serial.available() > 0)   //  Data in
	{
		inByte = Serial.read();
		temp += inByte;
		delay(15);
	}
	if (temp != "")
	{
		tt = temp.toInt();
		Serial.println(tt);
	}
	temp = "";

	//  Touch the screen
    for(int pos = 90; pos >= 60; pos --)    //maybe another num, just try!
    {
        myServo.write(pos);
        delay(15);
    }
    delay(tt);  //  ms

    for(int pos = 60; pos <= 90; pos ++)
    {
        myServo.write(pos);
        delay(15);
    }
}
