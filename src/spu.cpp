#include "../include/spu.h"
#include "../include/utils.h"
#include "../include/ims_debug.h"
#include <filesystem>
#include <fstream>
#include <string>
#include <cstdlib>
#include <iostream>

namespace fs = std::filesystem;


bool isSPUFound()
{
	return fs::exists("ims/SP_User/spu.txt");
}

void makeSPUData(std::string& spuData, const char* message)
{
	while ( true )
	{
		std::cout << message;
		std::cin >> spuData;

		if ( std::cin.fail() )
		{
			clearCin();
			continue;
		}

		std::cout << '\n';

		break;
	}
}

void initiateSPU(std::string spuName, std::string spuPasswd)
{

	fs::create_directories("ims/SP_User");

	std::ofstream spUserFile("ims/SP_User/spu.txt");

	if ( spUserFile.is_open() )
	{
		spUserFile << spuName << '\n';
		spUserFile << spuPasswd << '\n';
	}

	spUserFile.close();
}

bool startSPU()
{
	// WARNING: Development-only debug hook that deletes the IMS directory.
	// Must be removed in production as it resets all stored data.
	deleteIMSDirectory();

	if ( isSPUFound() )
	{
		return EXIT_SUCCESS;
	}

	// First-time setup flow.

	std::cout << "Welcome to the Inventory Management System!\n";
	std::cout << "If this is your first time make sure you read our README.md at our repository.\n\n";


	std::string spuName{};
	std::string spuPasswd{};

	// Pass-by-reference allows these calls to update our local strings directly
	makeSPUData(spuName, "Enter your special user name : ");
	makeSPUData(spuPasswd, "Enter your special user password : ");

	initiateSPU(spuName, spuPasswd);

	return EXIT_SUCCESS;
}
