#include <kernel/conv.h>

char* IntToString(int Value, int Base)
{
    static char Buffer[32] = {0};

    int Index = 30;
    for (; Value && Index; Index -= 1, Value /= Base)
    {
        Buffer[Index] = "0123456789abcdef"[Value % Base];
    }

    return &Buffer[Index + 1];
}


