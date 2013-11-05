/* Author: C1C Ryan Lamo
 * Created: 4 November 2013
 * Last Edited: 4 November 2013
 * Description: This program will implement a simple game in which the user moves a cursor
 * from the top left corner of the LCD to the bottom right corner.
 * Requires LCD.h and buttons/buttons.h to be included.
 * Documentation: I used Capt Branchflower's code on github as a guide for the general set-up
 * of the program.
 */
#include <msp430.h> 
int main(void) {
    WDTCTL = WDTPW | WDTHOLD;

    unsigned char player = initPlayer();

    _init_timer();
    init_buttons();
    _enable_interrupt();

    while(1)
    {

    }

	
	return 0;
}

void init_timer()
{

}

void init_buttons()
{

}
