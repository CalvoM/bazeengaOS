#!/bin/bash
rm *.com *.bin *.img *.o *.dis
nasm -f elf kern_entry.asm -o kern_entry.o
nasm -f bin boot.asm -o boot.com
nasm -f bin boot2.asm -o boot2.com
if [[ $? -eq 0 ]];then
        dd if=boot.com of=boot.img bs=512 count=1
        dd if=boot2.com of=boot.img bs=512 seek=1
        gcc -m32 -ffreestanding -fno-pic -c kernel.c -o kernel.o
        ld -m elf_i386 -o kernel.bin -Tkernel.ld kern_entry.o kernel.o --oformat binary
    if [[ $? -eq 0 ]];then
        cat boot.img kernel.bin > os.img
        #dd if=/dev/null of=os.img bs=512 seek=3
        qemu-system-x86_64 -s -drive format=raw,file=os.img
    else
        echo "Error during linking"
    fi  
   #bochs -f bochsrc.txt
else
    echo "Error while compiling Asm file"
fi