#!/bin/bash
nasm -f bin boot.asm -o boot.com
if [[ $? -eq 0 ]];then
    dd if=boot.com of=boot.img bs=512 count=1
    qemu-system-x86_64 -drive format=raw,file=boot.img
else
    echo "Error while compiling Asm file"
fi