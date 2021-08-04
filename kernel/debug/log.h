#pragma once
#include <kernel/debug/serial.h>

#define LogTrace(_Fmt) do { SerialWriteString("\x1b[1;37m[ TRACE ]\x1b[0m "); SerialWriteString(_Fmt); } while (0)
#define LogWarn(_Fmt) do { SerialWriteString("\x1b[1;33m[ WARN ]\x1b[0m "); SerialWriteString(_Fmt); } while (0)
#define LogError(_Fmt) do { SerialWriteString("\x1b[1;31m[ ERROR ]\x1b[0m "); SerialWriteString(_Fmt); } while (0)

