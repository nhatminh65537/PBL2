#include <conio.h>
#include "Input.h"

unsigned getKey()
{
    unsigned c = getch();
    if (c == 0 || c == 224)
    {
        c = getch();
        return c + 256;
    }
    return c;
}

