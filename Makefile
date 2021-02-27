all : os.img
run : all
		qemu-system-x86_64 -s -drive format=raw,file=os.img
os.img : boot.img kernel.bin
		cat boot.img kernel.bin > os.img
kernel.bin : kern_entry.o kernel.o
		ld -m elf_i386 -o kernel.bin -Tkernel.ld kern_entry.o kernel.o --oformat binary
kern_entry.o : kern_entry.asm
		nasm -f elf kern_entry.asm -o kern_entry.o
kernel.o : kernel.c
		gcc -m32 -ffreestanding -fno-pic -c kernel.c -o kernel.o
boot.img : boot.com boot2.com
		dd if=boot.com of=boot.img bs=512 count=1
		dd if=boot2.com of=boot.img bs=512 seek=1
boot.com : boot.asm
		nasm -f bin boot.asm -o boot.com
boot2.com : boot2.asm
		nasm -f bin boot2.asm -o boot2.com
clean:
		rm *.com *.o *.bin boot.img