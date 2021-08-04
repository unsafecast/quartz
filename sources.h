#ifdef BuildingKernel
    BuildFileC("kernel/main.c");
    BuildFileC("kernel/debug/serial.c");
    BuildFileC("kernel/io_ports.c");
    BuildFileC("kernel/conv.c");

    #if Bootloader == Limine
        BuildFileC("kernel/boot/limine/entry.c");
        BuildFileAsm("kernel/boot/limine/header.asm");
    #endif
#endif

