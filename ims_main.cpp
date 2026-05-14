#include "include/utils.h"
#include "include/spu.h"
#include "include/ims_debug.h"
#include "include/hash_data_encryption.h"
#include "include/auth.h"
#include "include/ims_tui.h"
#include <cstdlib>
#include <iostream>


//#define DEBUG

int main()
{
	// WARNING: Development-only debug hook that deletes the IMS directory.
	// Must be removed in production as it resets all stored data.
	deleteIMSDirectory();

	// It draws the fucking box in the middle of the termianl and all cmder commands are just in the middle I need to fix that shit later.
	// All I need is to make the project execute an outside window.
	// Well for linux I will use xterm and for windows I will use the ugly cmd shit.
	ims_tui::clearScreen();

	ims_tui::drawBox(MAIN_BOX_X1, MAIN_BOX_Y1, MAIN_BOX_X2, MAIN_BOX_Y2);
#ifndef DEBUG

	if ( !isSPUFound() )
	{
		// Initializes the Special User (SPU) environment if not found.
		//startSPU();

		// Just to make it easier to catch up with what happening on the screen.
		ims_utils::threadSleep(800);
		ims_tui::clearBoxInterior(MAIN_BOX_X1, MAIN_BOX_Y1, MAIN_BOX_X2, MAIN_BOX_Y2);
	}

	// Starts the login page.
	authenticator();

#endif

#ifdef DEBUG
	deleteIMSDirectory();
	ims_tui::drawBox(MAIN_BOX_X1, MAIN_BOX_Y1, MAIN_BOX_X2, MAIN_BOX_Y2);
	ims_tui::gotoMiddle(0, 0);
	//ims_tui::gotoxy(35, 4);
	std::cout << "Welcome to the Inventory Management System!";
	ims_tui::gotoxy(16, 6);
	std::cout << "If this is your first time make sure you read our README.md at our repository.";
	//ims_tui::clearBoxInterior(MAIN_BOX_X1, MAIN_BOX_Y1, MAIN_BOX_X2, MAIN_BOX_Y2);
	ims_tui::gotoxy(35, 40);
#endif
	return EXIT_SUCCESS;
}