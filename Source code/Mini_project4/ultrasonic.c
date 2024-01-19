#include "gpio.h"
#include "ultrasonic.h"
#include "icu.h"
#include <util/delay.h>

uint8 g_edgeCount = 0;
uint32 g_timeHigh = 0;
uint16 Distance = 0;


void Ultrasonic_init(void)
{
	ICU_ConfigType Userconfig = {F_CPU_8,RISING};
	ICU_setCallBack(Ultrasonic_edgeProcessing);
	ICU_init(&Userconfig);
	GPIO_setupPinDirection(ULTRASONIC_TRIGGER_PORT_ID,ULTRASONIC_TRIGGER_PIN_ID,PIN_OUTPUT);



}

void Ultrasonic_Trigger(void)
{
	GPIO_writePin(ULTRASONIC_TRIGGER_PORT_ID,ULTRASONIC_TRIGGER_PIN_ID,LOGIC_HIGH);
	_delay_us(10);
	GPIO_writePin(ULTRASONIC_TRIGGER_PORT_ID,ULTRASONIC_TRIGGER_PIN_ID,LOGIC_LOW);


}

uint16 Ultrasonic_readDistance(void)
{
	Ultrasonic_Trigger();

	if(g_edgeCount == 2){

		Distance = (g_timeHigh/58) + 1 ;
		g_edgeCount = 0;
	}


	return Distance;
}


void Ultrasonic_edgeProcessing(void)
{
	g_edgeCount++;
	if(g_edgeCount == 1)
	{
		/*
		 * Clear the timer counter register to start measurements from the
		 * first detected rising edge
		 */
		ICU_clearTimerValue();
		/* Detect falling edge */
		ICU_setEdgeDetectionType(FALLING);
	}
	else if(g_edgeCount == 2)
	{
		/* Store the High time value */
		g_timeHigh = ICU_getInputCaptureValue();
		/* Clear the timer counter register to start measurements again */
		ICU_clearTimerValue();
		/* Detect rising edge */
		ICU_setEdgeDetectionType(RISING);
	}


}
