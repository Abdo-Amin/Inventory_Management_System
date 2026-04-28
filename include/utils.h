#ifndef IMS_UTILS_H
#define IMS_UTILS_H

#include <string>

namespace ims_utils
{
	// Resets cin fail state and flushes the buffer to prevent input skipping.
	void clearCin();

	/**
	 * Prompts the user for input and stores it in the provided string.
	 * Performs basic input validation (stream failure check only).
	 * @param data Reference to the string where the input will be stored.
	 * @param message Prompt message displayed to the user.
	 */
	void initiateData(std::string& data, const char* message);

	// Pauses execution for the specified duration (in milliseconds).
	void threadSleep(unsigned int miliseconds);
}


#endif