/*
 *  Created on: Nov 4, 2013
 *      Author: C14Ryan.Lamo
 */

unsigned char initPlayer()
{
	return 0x80;
}

void printPlayer(unsigned char player)
{
	writeCommandByte(player);
	writeDataByte('*');
}

void clearPlayer(unsigned char player)
{
	writeCommandByte(player);
	writeDataByte(' ');
}

unsigned char movePlayer(unsigned char player, unsigned char direction)
{
	switch(direction)
	{

	}

	return player;
}

char didPlayerWin(unsigned char player)
{
	return player ==0xC7;
}


