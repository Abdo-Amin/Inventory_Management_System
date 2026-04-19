#ifndef IMS_UTILS_H
#define IMS_UTILS_H

// Resets cin fail state and flushes the buffer to prevent input skipping.
void clearCIN();

// Clears the terminal and resets cursor position using ANSI escape codes.
void clearScreen();

// Pauses execution for the specified duration (in milliseconds).
void threadSleep(int miliseconds);

#endif