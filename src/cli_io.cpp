#include "../include/cli_io.h"
#include <iostream>

namespace cli_io
{

	void clearScreen()
	{
		// Portably clears screen and moves cursor to home (top-left).
		// Used std::flush to clearScreen to ensure the terminal clears immediately without waiting for the next output.
		std::cout << "\033[2J\033[H" << std::flush;
	}

	void gotoxy(int x, int y)
	{
		printf("\033[%d;%dH", y, x);
	}




	/*
	*
	* COORDINATES

	x1y1                      x2y1




	x1y2					  x2y2



	*/



	void drawBox(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2)
	{
		// Adds lines to the top side and the bottom Side.
		for ( uint16_t curser = x1; curser <= x2; curser++ )
		{
			gotoxy(curser, y1);
			std::cout << "-" << std::flush;
			gotoxy(curser, y2);
			std::cout << "-" << std::flush;
		}

		for ( uint16_t curser = y1; curser <= y2; curser++ )
		{
			gotoxy(x1, curser);
			std::cout << "|" << std::flush;
			gotoxy(x2, curser);
			std::cout << "|" << std::flush;
		}

		//for ( uint16_t curser )

		gotoxy(x1, y1);
		std::cout << "+" << std::flush;
		gotoxy(x1, y2);
		std::cout << "+" << std::flush;
		gotoxy(x2, y1);
		std::cout << "+" << std::flush;
		gotoxy(x2, y2);
		std::cout << "+" << std::flush;
	}

}