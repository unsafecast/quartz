#include <stdio.h>

#define Limine 0
#include "./config.h"

#ifndef Compiler
    #define Compiler "clang -target i686-unknown-none-elf"
#endif

#ifndef Bootloader
    #error "Please define 'Bootloader' in config.h"
#endif

#if Bootloader == Limine
    #define LinkScript "kernel/boot/limine/link.ld"
#endif

#define CompFlags "-Wall -Wextra -ffreestanding -mno-red-zone -I./ -std=gnu11"
#define LinkFlags "-nostdlib -static -T" LinkScript
#define CompCommand Compiler " -c " CompFlags " -o $out $in"
#define LinkCommand Compiler " " LinkFlags " -o $out $in"
#define AsmCommand "nasm -felf32 -I./ -o $out $in"
#define CleanCommand "rm -rf build"

#define ImageCommand "rm -f build/quartz.img && " \
    "dd if=/dev/zero of=build/quartz.img bs=1M seek=64 count=10 && " \
    "parted -s build/quartz.img mklabel gpt && " \
    "parted -s build/quartz.img mkpart primary 2048s 100% && " \
    "echfs-utils -g -p0 build/quartz.img quick-format 512 && " \
    "echfs-utils -g -p0 build/quartz.img import build/quartzkern /quartzkern && " \
    "for file in ./sysroot/*; do echfs-utils -g -p0 build/quartz.img import $$file /$${file:10}; done && " \
    "limine-install build/quartz.img "

#define Rule(_Name, _Value) printf("rule " _Name "\n  command = " _Value "\n")
#define Compile(_File) printf("build build/" _File ".o: cc " _File "\n")
#define Assemble(_File) printf("build build/" _File ".o: asm " _File "\n")
#define Link(_File) printf("build build/" _File ": link ")
#define Command(_Name, _Command) Rule(_Name, _Command); printf("build " _Name ": " _Name "\n")

int main()
{
    Rule("cc", CompCommand);
    Rule("link", LinkCommand);
    Rule("asm", AsmCommand);

    Command("image", ImageCommand);

    #define BuildingKernel
        #define Target "quartzkern"
        #include "./build_target.h"
        #undef Target
    #undef BuildingKernel
}

