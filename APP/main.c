/*
 * main.c
 *
 *  Created on: Jan 28, 2023
 *      Author: rerom
 */

#include"../AutomatedCar/Car.h"
#include<avr/io.h>
#define BlackLine        1
#define WhiteLine        0
#define MinimumDistance  15
#define MaxTrials        3

#define InstructionDelay  25

#define ServoDelay        30

void DelayFunc(volatile U32 i){
	volatile U32 j;
	for(j=0;j<i;j++){

	}
}

int main(){
	CarInit();
	DioSetPinDir(GD,PIN3,Output);
	U8 MiddleIRdigitalVal, RightIRdigitalVal, LeftIRdigitalVal;

	while(1)
	{



#if 0
		while(!CarDetectObstacle()){

			TCRT5000GetVal(&MiddleIRdigitalVal, &RightIRdigitalVal, &LeftIRdigitalVal);

			/* follow black line forward as long as there is no curvature */
			if (MiddleIRdigitalVal == BlackLine && RightIRdigitalVal== WhiteLine && LeftIRdigitalVal == WhiteLine)
			{
				CarForwardDir();
			}
			else
			{
				CarBrake();

				/*follow black line right with no sharp curvature */
				if (RightIRdigitalVal== BlackLine && MiddleIRdigitalVal== WhiteLine )
				{
					CarRotateRight(IRMode);
					TCRT5000GetVal(&MiddleIRdigitalVal, &RightIRdigitalVal, &LeftIRdigitalVal);
					if(MiddleIRdigitalVal== WhiteLine && LeftIRdigitalVal==WhiteLine && RightIRdigitalVal== WhiteLine)
						CarRotateLeft(IRMode);
				}

				/*follow black line left with no sharp curvature */
				else if (LeftIRdigitalVal == BlackLine && MiddleIRdigitalVal== WhiteLine)
				{
					CarRotateLeft(IRMode);
					TCRT5000GetVal(&MiddleIRdigitalVal, &RightIRdigitalVal, &LeftIRdigitalVal);

					if(MiddleIRdigitalVal== WhiteLine && LeftIRdigitalVal==WhiteLine && RightIRdigitalVal== WhiteLine)
						CarRotateRight(IRMode);
				}

				/*sharp turn to the right*/
				else if (MiddleIRdigitalVal == BlackLine && RightIRdigitalVal== BlackLine)
				{
					CarDriftRight();
					CarDelay(20);
				}

				/*sharp turn to the left */
				else if (MiddleIRdigitalVal == BlackLine && LeftIRdigitalVal== BlackLine)
				{
					CarDriftLeft();
					CarDelay(20);

				}
				else if(MiddleIRdigitalVal== WhiteLine && LeftIRdigitalVal==WhiteLine && RightIRdigitalVal== WhiteLine)
				{
					//CarStop();
					CarBrake();
					CarRotateLeft(IRMode);
				}

			}
		}
#endif


		CarDelay(60);
		ServoSetAngle(MidAngle);
		CarForwardDir();
		while(CarDetectObstacle()){
			CarStop();
			CarDelay(60);
			CarRotateServo(MidPosition, RightPosition);
			CarDelay(350);

			if(CarDetectObstacle()){
				CarRotateServo(RightPosition, LeftPosition);
				CarDelay(250);
				if(CarDetectObstacle()){
					CarRotateServo(LeftPosition, MidPosition);
					CarDelay(250);
					CarReverseDir();
					CarDelay(125);
					CarStop();
					CarDelay(250);
				}
				else{
					ServoSetAngle(MidAngle);
					CarDelay(60);
					CarRotateLeft(ObstacleMode);
					CarStop();
					CarDelay(125);
					CarForwardDir();
					CarDelay(180);
					CarStop();
					CarDelay(64);
					CarRotateRight(ObstacleMode);
					CarStop();
					CarDelay(64);
					CarForwardDir();
					CarDelay(280);
					CarStop();
					CarDelay(64);
					CarRotateRight(ObstacleMode);
					TCRT5000GetVal(&MiddleIRdigitalVal, &RightIRdigitalVal, &LeftIRdigitalVal);

					while(RightIRdigitalVal != BlackLine && MiddleIRdigitalVal!=BlackLine)
					{
						CarForwardDir();
						TCRT5000GetVal(&MiddleIRdigitalVal, &RightIRdigitalVal, &LeftIRdigitalVal);

					}
					CarStop();
					CarDelay(250);
				}
			}
			else{
				ServoSetAngle(MidAngle);
				CarDelay(60);
				CarRotateRight(IRMode);
				CarDelay(175);
				CarStop();
				CarDelay(1000);
				CarForwardDir();
				CarDelay(300);
				CarStop();
				CarDelay(1000);
				CarRotateLeft(IRMode);
				CarDelay(100);
				CarStop();
				CarDelay(1000);
				CarForwardDir();
				CarDelay(400);
				CarStop();
				CarDelay(1000);
				CarRotateLeft(IRMode);
				CarDelay(100);
				CarStop();
				CarDelay(1000);
				CarForwardDir();
				TCRT5000GetVal(&MiddleIRdigitalVal, &RightIRdigitalVal, &LeftIRdigitalVal);
				while(LeftIRdigitalVal != BlackLine && MiddleIRdigitalVal!=BlackLine&& RightIRdigitalVal!=BlackLine)
				{
					TCRT5000GetVal(&MiddleIRdigitalVal, &RightIRdigitalVal, &LeftIRdigitalVal);
				}
				CarStop();
				CarDelay(8000);

			}
		}

	}

	return 0;
}

