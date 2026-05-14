#include "../include/utils.h"
#include "../include/ims_tui.h"
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
		ims_utils::threadSleep(800);
		ims_tui::clearScreen();
	}
}