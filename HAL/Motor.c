/*
 * Motor.c
 *
 *  Created on: Feb 16, 2023
 *      Author: rerom
 */
#include"Motor.h"

void MotorInit(){
	PWMInit(Timer0Channel);
	DioSetPinDir(GC,HA1,Output);
	DioSetPinDir(GC,HA2,Output);
	DioSetPinDir(GC,HA3,Output);
	DioSetPinDir(GC,HA4,Output);
}

void MotorSetDirection(U8 Direction){
	switch(Direction){
		case Reverse:
			DioSetPinVal(GC,HA1,Low);
			DioSetPinVal(GC,HA2,High);
			DioSetPinVal(GC,HA3,Low);
			DioSetPinVal(GC,HA4,High);
		break;
		case Forward:
			DioSetPinVal(GC,HA1,High);
			DioSetPinVal(GC,HA2,Low);
			DioSetPinVal(GC,HA3,High);
			DioSetPinVal(GC,HA4,Low);
		break;
	}
}

void MotorSetSpeed(U8 Speed){
	PWMSetDutyCycle(Timer0Channel,Speed);
}

void MotorStart(){
	PWMStart(Timer0Channel);
}

void MotorStartLeft(){
	DioSetPinVal(GC,HA1,High);
	DioSetPinVal(GC,HA2,Low);
}

void MotorStartRight(){
	DioSetPinVal(GC,HA3,High);
	DioSetPinVal(GC,HA4,Low);
}

void MotorStopLeft(){
	DioSetPinVal(GC,HA1,Low);
	DioSetPinVal(GC,HA2,Low);
}

void MotorStopRight(){
	DioSetPinVal(GC,HA3,Low);
	DioSetPinVal(GC,HA4,Low);
}

void MotorStop(){
	DioSetPinVal(GC,HA1,Low);
	DioSetPinVal(GC,HA2,Low);
	DioSetPinVal(GC,HA3,Low);
	DioSetPinVal(GC,HA4,Low);
	PWMStop(Timer0Channel);
}
void LeftMotorForward(){
	DioSetPinVal(GC,HA1,High);
	DioSetPinVal(GC,HA2,Low);
}
void LeftMotorReverse(){
	DioSetPinVal(GC,HA1,Low);
	DioSetPinVal(GC,HA2,High);
}
void RightMotorForward(){
	DioSetPinVal(GC,HA3,High);
	DioSetPinVal(GC,HA4,Low);
}
void RightMotorReverse(){
	DioSetPinVal(GC,HA3,Low);
	DioSetPinVal(GC,HA4,High);
}


