#include "include/spu.h"
#include <cstdlib>

int main()
{
	// Initializes the Special User (SPU) environment and system folders.
	// Returns EXIT_SUCCESS (0) if the setup or check finishes without error.
	return startSPU();
