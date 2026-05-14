#ifndef IMS_AUTH_H
#define IMS_AUTH_H

#include <cstdint>

const int16_t LOGIN_BOX_X1{26};
const int16_t LOGIN_BOX_Y1{7};
const int16_t LOGIN_BOX_X2{91};
const int16_t LOGIN_BOX_Y2{16};

enum accessType
{
	SPU,
	AU
};

void authenticator();

accessType typeOfLogin();

void authPage();

void checkUserSPU(std::string username, std::string password);

void checkUserAU(std::string username, std::string password);


#endif