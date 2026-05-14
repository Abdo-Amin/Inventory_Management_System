#include "../include/spu.h"
#include "../include/utils.h"
#include <iostream>
#include <limits>
#include <thread>
#include <chrono>

namespace ims_utils
{

	void clearCin()
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	void initiateData(std::string& data, const char* message)
	{
		while ( true )
		{
			std::cout << message;
			std::cin >> data;

			clearCin();

			std::cout << '\n';

			break;
		}
	}

	void threadSleep(uint16_t miliseconds)
	{
		// Used chrono for high-precision sleeping.
		std::this_thread::sleep_for(std::chrono::milliseconds(miliseconds));
	}

}