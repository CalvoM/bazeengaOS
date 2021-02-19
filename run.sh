#!/bin/bash
nasm -f bin boot.asm -o boot.com
nasm -f bin boot2.asm -o boot2.com
if [[ $? -eq 0 ]];then
    dd if=boot.com of=boot.img bs=512 count=1
    dd if=boot2.com of=boot.img bs=512 seek=1
   qemu-system-x86_64 -drive format=raw,file=boot.img
   #bochs -f bochsrc.txt
else
    echo "Error while compiling Asm file"
fi