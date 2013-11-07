lab5
====

Description: 

This program allows the user to play a simple game. The purpose of the game is to move a cursor from the top left corner of 
the LCD to the bottom right corner of the LCD. The player moves the cursor through push buttons connected to pin buttons
1, 2, 3 and 4. 

Pin1 BIT1 - moves the cursor right
Pin1 BIT2 - moves the cursor left
Pin1 BIT3 - moves the cursor up
Pin1 BIT4 - moves the cursor down

The user must input a button push within two seconds of the last button push or the game is over. To restart the game after 
the "You Won" or "Game Over" messages, the user must push any button. 

External Files Necessary for Program: 

Header files used for the implementation of this program are below: 
button.h from Capt Branchflower's buttons file. 
LCD.h from Capt Branchflower's LCD file. 
game.h from C1C Ryan Lamo's lab5 file. 
msp430.h 

