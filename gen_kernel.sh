gcc -m32 -ffreestanding -fno-pic -c kernel.c kernel.o
ld -m elf_i386 -o kernel.bin -Ttext 0x1000 kernel.o --oformat binary