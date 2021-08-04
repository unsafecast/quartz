#pragma once
#include <stdbool.h>

bool SerialDebugInit();
void SerialWriteChar(char Char);
void SerialWriteString(const char* String);

