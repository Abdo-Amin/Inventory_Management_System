#include "include/spu.h"
#include "include/ims_debug.h"
#include "include/hash_data_encryption.h"
#include <cstdlib>

int main()
{
	// WARNING: Development-only debug hook that deletes the IMS directory.
	// Must be removed in production as it resets all stored data.
	deleteIMSDirectory();

	if ( !isSPUFound() )
	{
		// Initializes the Special User (SPU) environment if not found.
		startSPU();
	}

	return EXIT_SUCCESS;
}