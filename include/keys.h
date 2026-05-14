#ifndef IMS_KEYS_H
#define IMS_KEYS_H

#ifdef _WIN32

#include <conio.h>

namespace ims_keys
{
	bool checkKeyChar(char keySmall, char keyCapital);

	char checkKey();

}

#else

// SHOULD ADD PORTABILITY TO LINUX LOL!!




#endif

#endif