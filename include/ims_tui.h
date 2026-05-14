#ifndef IMS_CLI_IO_H
#define IMS_CLI_IO_H

#include <cstdint>
#include <string>

const int16_t MAIN_BOX_X1{2};
const int16_t MAIN_BOX_Y1{1};
const int16_t MAIN_BOX_X2{120};
const int16_t MAIN_BOX_Y2{30};

enum WritingType
{
	MIDDLE,
	NEWLINE
};

namespace ims_tui
{
	// Clears the terminal and resets cursor position using ANSI escape codes.
	void clearScreen();

	// Move cursor (ANSI escape)
	void gotoxy(int16_t x, int16_t y);

	void gotoMiddle(int16_t x, int16_t y);

	void gotoNewLine(int16_t x, int16_t y);

	// Draws a box to contain the content inside.
	void drawBox(int16_t x1, int16_t y1, int16_t x2, int16_t y2);

	// Clears all stirngs inside a box.
	void clearBoxInterior(int16_t x1, int16_t y1, int16_t x2, int16_t y2);

	void clearBoxLine(int16_t line);

	void clearBoxCustomLine(int16_t x1, int16_t x2, int16_t line);

	void writeInBox(WritingType typeOfText, int16_t lineFineTune, int16_t lineNumber, std::string text);
}

#endif