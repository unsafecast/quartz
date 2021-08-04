#include <kernel/boot/handover.h>
#include <kernel/debug/serial.h>
#include <kernel/conv.h>
#include <kernel/debug/log.h>

void PrintSplash()
{
    SerialWriteString("\n"
        "________  ___  ___  ________  ________  _________  ________     \n"
        "|\\   __  \\|\\  \\|\\  \\|\\   __  \\|\\   __  \\|\\___   ___\\\\_____  \\    \n"
        "\\ \\  \\|\\  \\ \\  \\\\\\  \\ \\  \\|\\  \\ \\  \\|\\  \\|___ \\  \\_|\\|___/  /|   \n"
        " \\ \\  \\\\\\  \\ \\  \\\\\\  \\ \\   __  \\ \\   _  _\\   \\ \\  \\     /  / /   \n"
        "  \\ \\  \\\\\\  \\ \\  \\\\\\  \\ \\  \\ \\  \\ \\  \\\\  \\|   \\ \\  \\   /  /_/__  \n"
        "   \\ \\_____  \\ \\_______\\ \\__\\ \\__\\ \\__\\\\ _\\    \\ \\__\\ |\\________\\\n"
        "    \\|___| \\__\\|_______|\\|__|\\|__|\\|__|\\|__|    \\|__|  \\|_______|\n"
        "          \\|__|\n\n"
    );
}

void Init(handover* Handover)
{
    SerialDebugInit();

    PrintSplash();
    LogTrace("Welcome to the kernel!\n");
}

