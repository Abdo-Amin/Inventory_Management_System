#include "../include/utils.h"
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

void deleteIMSDirectory()
{
	// Remove the entire IMS directory tree if it exists
	if ( fs::remove_all("ims") )
	{
		// Notify developer that the reset was performed
		std::cerr << "DEBUG : REMOVED IMS FOLDER!\n";
		threadSleep(800);
		clearScreen();
	}
}