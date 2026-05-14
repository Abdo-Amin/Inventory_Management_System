#include "../include/keys.h"

#ifdef _WIN32

#include <conio.h>
#include <iostream>
#include <cstdint>

namespace ims_keys
{

    bool checkKeyChar(char keySmall, char keyCapital)
    {
        char ch = _getch();

        if ( ch == keySmall || ch == keyCapital )
        {
            return true;
        }

        return false;
    }

    char checkKey()
    {
        char ch = _getch();

        return ch;
    }
}

#else
	//SHOULD ADD LINUX PORTABILITY LOL!!!!!
#endif