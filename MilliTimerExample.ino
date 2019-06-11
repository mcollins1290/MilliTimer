#include "Arduino.h"
#include "MilliTimer.h"

MilliTimer Timer1(5000ul,true);  // 5 Seconds
MilliTimer Timer2(10000ul,true); // 10 Seconds
MilliTimer Timer3(15000ul,true); // 15 Seconds

int timer1_count = 0;
int timer2_count = 0;
int timer3_count = 0;

bool timer1_expired = false;
bool timer2_expired = false;
bool timer3_expired = false;

void setup()
{
	Serial.begin(9600);

	Timer1.start();
	Timer2.start();
	Timer3.start();
}

void loop()
{
	if(Timer1.isElapsed())
	{
		timer1_count++;

		Serial.print("Timer 1 elapsed. Count: ");
		Serial.print(timer1_count);
		Serial.print(". Timer elapsed duration: ");
		Serial.println(Timer1.elapsedDuration());

		Timer1.restart();

		if(timer1_count == 5)
		{
			timer1_expired = true;
			Timer1.stop();
			Serial.println("!!! TIMER 1 EXPIRED !!!");
		}
	}

	if(Timer2.isElapsed())
	{
		timer2_count++;

		Serial.print("Timer 2 elapsed. Count: ");
		Serial.print(timer2_count);
		Serial.print(". Timer elapsed duration: ");
		Serial.println(Timer2.elapsedDuration());

		Timer2.restart();

		if(timer2_count == 5)
		{
			timer2_expired = true;
			Timer2.stop();
			Serial.println("!!! TIMER 2 EXPIRED !!!");
		}
	}

	if(Timer3.isElapsed())
	{
		timer3_count++;

		Serial.print("Timer 3 elapsed. Count: ");
		Serial.print(timer3_count);
		Serial.print(". Timer elapsed duration: ");
		Serial.println(Timer3.elapsedDuration());

		Timer3.restart();

		if(timer3_count == 5)
		{
			timer3_expired = true;
			Timer3.stop();
			Serial.println("!!! TIMER 3 EXPIRED !!!");
		}
	}

	if(timer1_expired == true && timer2_expired == true && timer3_expired == true)
	{
		stop();
	}
}

void stop()
{
	Serial.println("!!! STOP!!!");
	while(true)
	{}
}
