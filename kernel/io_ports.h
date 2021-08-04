#pragma once
#include <stdint.h>

#define SerialData1 0x3f8
#define SerialFifoCommand1 (SerialData1 + 2)
#define SerialLineCommand1 (SerialData1 + 3)
#define SerialModemCommand1 (SerialData1 + 4)
#define SerialLineStatus1 (SerialData1 + 5)

void WriteIO(uint16_t Port, uint8_t Value);
uint8_t ReadIO(uint16_t Port);

