#include"ultrasonic.h"
#include"lcd.h"
#include <avr/io.h>

int main(void){

	SREG |= (1<<7);
	Ultrasonic_init();
	LCD_init();
	LCD_displayString("Distance: ");
	uint16 distance = 0;

	while(1){

		distance = Ultrasonic_readDistance();

		LCD_moveCursor(0,9);
		LCD_intgerToString(distance);
		LCD_displayCharacter(' ');
		LCD_displayString("cm");
		LCD_displayCharacter(' ');



	}

}
