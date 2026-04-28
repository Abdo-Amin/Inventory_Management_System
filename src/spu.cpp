#include "../include/spu.h"
#include "../include/utils.h"
#include "../include/ims_debug.h"
#include "../include/hash_data_encryption.h"
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
	std::cout << "Welcome to the Inventory Management System!\n";
	std::cout << "If this is your first time make sure you read our README.md at our repository.\n\n";

	std::string spuName{};
	std::string spuPasswd{};

	ims_utils::initiateData(spuName, "Enter your special user name : ");
	ims_utils::initiateData(spuPasswd, "Enter your special user password : ");

	// Verify libsodium hashing succeeded before proceeding
	if ( hashEncyptData(spuPasswd) == EXIT_FAILURE )
	{
		std::abort(); 
	}

	initiateSPU(spuName, spuPasswd);

	return;
}