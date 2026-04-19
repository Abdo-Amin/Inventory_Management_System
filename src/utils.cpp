#include "../include/utils.h"
#include <iostream>
#include <limits>
#include <thread>
#include <chrono>

void clearCIN()
{
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void clearScreen()
{
	// Portably clears screen and moves cursor to home (top-left).
	// Used std::flush to clearScreen to ensure the terminal clears immediately without waiting for the next output.
	std::cout << "\033[2J\033[H" << std::flush;
}

void threadSleep(int miliseconds)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(miliseconds));
}

