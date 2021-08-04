#include <kernel/io_ports.h>

void WriteIO(uint16_t Port, uint8_t Value)
{
    asm volatile ("outb %0, %1" : : "a"(Value), "Nd"(Port));
}

uint8_t ReadIO(uint16_t Port)
{
    uint8_t Value;
    asm volatile ("inb %1, %0" : "=a"(Value) : "Nd"(Port));

    return Value;
}

