#include <kernel/boot/handover.h>
#include <kernel/debug/serial.h>
#include <kernel/conv.h>
#include <kernel/debug/log.h>

void Init(handover* Handover)
{
    SerialDebugInit();

    LogTrace("Welcome to the kernel!\n");
}

