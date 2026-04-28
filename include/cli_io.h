#ifndef IMS_CLI_IO_H
#define IMS_CLI_IO_H

#include <cstdint>

namespace cli_io
{
	// Clears the terminal and resets cursor position using ANSI escape codes.
	void clearScreen();

	// Move cursor (ANSI escape)
	void gotoxy();

	// Draws a box to contain the content inside.
	void drawBox(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);
}

#endif