#include "../include/ims_tui.h"

#include <cstdlib>
#include <iostream>
#include <format>

namespace ims_tui
{



	void clearScreen()
	{
		// Portably clears screen and moves cursor to home (top-left).
		// Used std::flush to clearScreen to ensure the terminal clears immediately without waiting for the next output.
		std::cout << "\033[2J\033[H" << std::flush;
	}

	void gotoxy(int16_t x, int16_t y)
	{
		std::cout << std::format("\033[{};{}H", y, x);
	}

	void gotoMiddle(int16_t x, int16_t y)
	{
		std::cout << std::format("\033[{};{}H", y + ( MAIN_BOX_Y1 + 2 ), x + ( MAIN_BOX_X2 / 2 ) );
	}

	void gotoNewLine(int16_t x, int16_t y)
	{
		std::cout << std::format("\033[{};{}H", y + ( MAIN_BOX_Y1 + 2 ), x + ( MAIN_BOX_X1 + 1 ) );
	}

	// The main coordinates of the box that contains the content of the program.
	/*
	*	  	    COORDINATES
	*
	*  x1y1                      x2y1
	*
	*
	*  x1y2				    	 x2y2
	*/
	void drawBox(int16_t x1, int16_t y1, int16_t x2, int16_t y2)
	{
		// Adds lines to the top side and the bottom side.
		for ( int16_t curser = x1; curser <= x2; curser++ )
		{
			gotoxy(curser, y1);
			std::cout << "-" << std::flush;
			gotoxy(curser, y2);
			std::cout << "-" << std::flush;
		}

		// Add lines to the right side and the left side.
		for ( int16_t curser = y1; curser <= y2; curser++ )
		{
			gotoxy(x1, curser);
			std::cout << "|" << std::flush;
			gotoxy(x2, curser);
			std::cout << "|" << std::flush;
		}

		// Add '+' to the corners.
		gotoxy(x1, y1);
		std::cout << "+" << std::flush;
		gotoxy(x1, y2);
		std::cout << "+" << std::flush;
		gotoxy(x2, y1);
		std::cout << "+" << std::flush;
		gotoxy(x2, y2);
		std::cout << "+" << std::flush;
	}

	void clearBoxInterior(int16_t x1, int16_t y1, int16_t x2, int16_t y2)
	{
		for ( int16_t row{y1 + 1}; row < y2; row++ )
		{
			gotoxy(x1 + 1, row);
			for ( int16_t col{x1 + 1}; col < x2; col++ )
			{
				std::cout << " ";
			}
		}
	}

	void clearBoxLine(int16_t line)
	{
		gotoxy(MAIN_BOX_X1 + 1, ( MAIN_BOX_Y1 + 2 ) + line );

		for ( int16_t i{MAIN_BOX_X1 + 1}; i < MAIN_BOX_X2; i++ )
		{ 
			std::cout << " ";
		}

		gotoxy(MAIN_BOX_X1 + 1, (MAIN_BOX_Y1 + 2) + line);
	}

	void clearBoxCustomLine(int16_t x1, int16_t x2, int16_t line)
	{
		gotoxy(x1, (MAIN_BOX_Y1 + 2) + line);

		for ( int16_t i{x1}; i < x2; i++ )
		{
			std::cout << " ";
		}

		gotoxy(x1, (MAIN_BOX_Y1 + 2) + line);
	}


	void writeInBox(WritingType typeOfText, int16_t lineFineTune, int16_t lineNumber, std::string text)
	{
		switch ( typeOfText )
		{

		case MIDDLE:
			gotoMiddle(lineFineTune, lineNumber);
			std::cout << text;
			break;


		case NEWLINE:
			gotoNewLine(lineFineTune, lineNumber);
			std::cout << text;
			break;

		}
	}
}