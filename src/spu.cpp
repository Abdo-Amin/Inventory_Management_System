 #include "../include/spu.h"
#include "../include/utils.h"
#include "../include/ims_debug.h"
#include "../include/hash_data_encryption.h"
#include "../include/ims_tui.h"
#include "../include/keys.h"
#include <filesystem>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>


namespace fs = std::filesystem;

bool isSPUFound()
{
	return fs::exists("ims/SP_User/spu.txt");
}


void initiateSPU(std::string spuName, std::string spuPasswd)
{
	// Create the directory path for the user data
	fs::create_directories("ims/SP_User");

	std::ofstream spUserFile("ims/SP_User/spu.txt");

	if ( spUserFile.is_open() )
	{
		// Format stored as name:hash
		spUserFile << spuName << ':';
		spUserFile << spuPasswd << '\n';
	}

	spUserFile.close();
}

void startSPU()
{
	std::string spuName{};
	std::string spuPasswd{};

	ims_tui::writeInBox(MIDDLE, -22, 0, "Welcome to the Inventory Management System!");
	ims_tui::writeInBox(NEWLINE, 18, 2, "If this is your first time make sure you read our README.md at our repository.");

	while(true)
	{
		ims_tui::gotoNewLine(12, 5);
		ims_utils::initiateData(spuName, "Enter your special user name : ");
		ims_tui::gotoNewLine(12, 6);
		std::cout << "Do you confirm your new special user name? (y/n) ";
		if ( ims_keys::checkKeyChar('y', 'Y') )
		{
			ims_utils::threadSleep(100);
			ims_tui::clearBoxLine(6);
			ims_tui::clearBoxLine(5);
			ims_utils::threadSleep(200);
			break;
		}

		ims_tui::clearBoxLine(6);
		ims_tui::clearBoxLine(5);
		ims_utils::threadSleep(200);

	}

	while ( true )
	{
		ims_tui::gotoNewLine(12, 5);
		ims_utils::initiateData(spuPasswd, "Enter your special user password : ");
		ims_tui::gotoNewLine(12, 6);
		std::cout << "Do you confirm your new special user password? (y/n) ";
		if ( ims_keys::checkKeyChar('y', 'Y') )
		{
			ims_utils::threadSleep(100);
			ims_tui::clearBoxLine(6);
			ims_tui::clearBoxLine(5);
			ims_utils::threadSleep(200);
			break;
		}

		ims_tui::clearBoxLine(6);
		ims_tui::clearBoxLine(5);
		ims_utils::threadSleep(200);

	}

	// Verify libsodium hashing succeeded before proceeding
	if ( hashEncyptData(spuPasswd) == EXIT_FAILURE )
	{
		std::abort(); 
	}

	initiateSPU(spuName, spuPasswd);

	return;
}