#include "..\include\auth.h"
#include "..\include\utils.h"
#include "..\include\hash_data_encryption.h"
#include "..\include\ims_tui.h"
#include "..\include\keys.h"
#include <iostream>
#include <string>
#include <cstdint>


accessType typeOfLogin()
{
	ims_tui::writeInBox(MIDDLE, -10, 5, "Choose Login as : ");
	ims_tui::writeInBox(MIDDLE, -15, 8, "Login as Special User	(1)");
	ims_tui::writeInBox(MIDDLE, -15, 9, "Login as Admin User		(2)");

	ims_tui::gotoxy(300, 300);

	while ( true )
	{
		char choice{ims_keys::checkKey()};

		if ( choice == '1' )
		{
			ims_utils::threadSleep(260);
			ims_tui::clearBoxInterior(LOGIN_BOX_X1, LOGIN_BOX_Y1, LOGIN_BOX_X2, LOGIN_BOX_Y2);
			return SPU;
		}
		else if ( choice == '2' )
		{
			ims_utils::threadSleep(260);
			ims_tui::clearBoxInterior(LOGIN_BOX_X1, LOGIN_BOX_Y1, LOGIN_BOX_X2, LOGIN_BOX_Y2);
			return AU;
		}
	}
}


void authPage()
{
	ims_tui::writeInBox(MIDDLE, -10, 0, "AUTHENTICATION PAGE");

	ims_tui::gotoNewLine(30, 7);
	std::cout << "Enter your username : ";

	ims_tui::gotoNewLine(30, 9);
	std::cout << "Enter your password : ";

}

void checkUserSPU(std::string username, std::string password)
{
	
}

void checkUserAU(std::string username, std::string password)
{

}



void authenticator()
{
	ims_tui::drawBox(LOGIN_BOX_X1, LOGIN_BOX_Y1, LOGIN_BOX_X2, LOGIN_BOX_Y2);

	accessType typeOfAccess{typeOfLogin()};
			
	authPage();

	std::string username;
	std::string password;
	const int16_t WRITING_COL{52};

	while ( true )
	{
		ims_tui::gotoNewLine(WRITING_COL, 7);
		ims_utils::initiateData(username, "");

		ims_tui::gotoNewLine(WRITING_COL, 9);
		ims_utils::initiateData(password, "");

		if ( true )
		{
			ims_tui::writeInBox(MIDDLE, -25, 15, "Login Failed : Check your username or password.");
			ims_utils::threadSleep(270);
			ims_tui::clearBoxCustomLine(WRITING_COL+2, LOGIN_BOX_X2, 7);
			ims_tui::clearBoxCustomLine(WRITING_COL+2, LOGIN_BOX_X2, 9);
		}
	}
}