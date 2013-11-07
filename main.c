/* Author: C1C Ryan Lamo
 * Created: 4 November 2013
 * Last Edited: 4 November 2013
 * Description: This program will implement a simple game in which the user moves a cursor
 * from the top left corner of the LCD to the bottom right corner.
 * Requires LCD.h and buttons/buttons.h to be included.
 * Documentation: I used Capt Branchflower's code on github as a guide for the general set-up
 * of the program. I looked to Jason Mossing's file to get an idea of how to deal with the boundary
 * conditions of the LCD to move the cursor using the case command.
 */
#include <msp430.h> 
#include "game.h"
#include "LCD/LCD.h"
#include "buttons/button.h"


void init_buttons();
void movecursor(char buttonToTest);
void init_timer();


char player =0;
char CountTimer = 0;
char buttonToTest = 0;

int main(void) {
    WDTCTL = WDTPW | WDTHOLD;

    player = initPlayer();

    initSPI();
    LCDinit();
    LCDclear();

    printPlayer(player);

    init_timer();
    init_buttons();
   __enable_interrupt();



    while(1)
    {

    	if (CountTimer >=4)
    	{
    		TACTL &= ~TAIE;
    		LCDclear();
    		cursorToLineOne();
    		writeString("Game");
    		cursorToLineTwo();
    		writeString("Over");

    	}

    }

	
	return 0;
}


void init_timer()
{
	TACTL &= ~(MC1|MC0);
	TACTL |= TACLR;
	TACTL |= TASSEL1;
	TACTL |= ID1|ID0;
	TACTL &= ~ TAIFG;
	TACTL |= MC1;
	TACTL |= TAIE;

}

#pragma vector=TIMER0_A1_VECTOR
__interrupt void TIMER0_A1_ISR()
{
	TACTL &= ~TAIFG;
	CountTimer++;
}

void init_buttons()
{
	configureP1PinAsButton(BIT1|BIT2|BIT3|BIT4);

//	P1DIR &= ~(BIT1|BIT2|BIT3|BIT4);

	P1IE |= BIT1|BIT2|BIT3|BIT4;
	P1IES |= BIT1|BIT2|BIT3|BIT4;

//	P1REN |= BIT1|BIT2|BIT3|BIT4;
//	P1OUT |= BIT1|BIT2|BIT3|BIT4;

	P1IFG &= ~(BIT1|BIT2|BIT3|BIT4);


}

void TestForButtonPress(char buttonToTest)
{
	if (buttonToTest & P1IFG)
	{
		if (buttonToTest & P1IES)
		{
			movecursor(buttonToTest);

		}else
		{
			debounce();
		}

		P1IES ^= buttonToTest;
		P1IFG &= ~buttonToTest;
	}
}

void movecursor(char buttonToTest)
{
	switch(buttonToTest){

	case BIT1:
		player = movePlayer(player,RIGHT);
		break;
	case BIT2:
		player = movePlayer(player,LEFT);
		break;
	case BIT3:
		player = movePlayer(player,UP);
		break;
	case BIT4:
		player = movePlayer(player,DOWN);

	}
}

#pragma vector = PORT1_VECTOR
__interrupt void Port_1_ISR(void)
{
	TestForButtonPress(BIT1|BIT2|BIT3|BIT4);
}
