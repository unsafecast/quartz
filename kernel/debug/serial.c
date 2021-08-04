#include <kernel/debug/serial.h>
#include <kernel/io_ports.h>

bool SerialDebugInit()
{
    WriteIO(SerialFifoCommand1, 0x0);  // Disable interrupts
    WriteIO(SerialLineCommand1, 0x80);  // Enable DLAB (set baud rate divisor)
    WriteIO(SerialData1, 0x03);  // Set baud rate divisor to 3 (38400 baud) - low byte
    WriteIO(SerialData1, 0x00);  //                                         - high byte
    WriteIO(SerialLineCommand1, 0x03);  // 8-bit characters, with no parity
    WriteIO(SerialFifoCommand1, 0xc7);  // Enable the FIFO Queue, and clear it
    WriteIO(SerialLineStatus1, 0x1e);  // Set loopback mode

    WriteIO(SerialModemCommand1, 0x0f);
    return true;
}

static bool IsTransmitEmpty()
{
    return ReadIO(SerialLineStatus1) & 0x20;
}

void SerialWriteChar(char Char)
{
    while (!IsTransmitEmpty());
    WriteIO(SerialData1, Char);
}

void SerialWriteString(const char* String)
{
    while (*String)
    {
        SerialWriteChar(*String);
        String++;
    }
}

