#include "include/spu.h"
#include <cstdlib>

int main()
{
	// Initializes the Special User (SPU) environment if not found.
	checkSPU();

	return EXIT_SUCCESS;
}