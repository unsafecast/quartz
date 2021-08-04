#include <kernel/boot/limine/stivale2.h>
#include <kernel/boot/handover.h>

#include <stdint.h>
#include <stddef.h>

static uint8_t KernelStack[4096];
uintptr_t KernelStackTop = (uintptr_t)KernelStack + sizeof(KernelStack);

void Init(handover* Handover);
void EarlyInit(struct stivale2_struct* Stivale)
{
    handover Handover;
    Init(&Handover);

    while (1) { asm volatile ("hlt"); }
}

