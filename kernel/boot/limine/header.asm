extern KernelStackTop
extern EarlyInit

section .stivale2hdr
align 4
Stivale2Header:
    dq EarlyInit
    dq KernelStackTop
    dq 0
    dq 0

