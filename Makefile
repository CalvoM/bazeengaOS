c_sources = $(wildcard kernel/*.c drivers/*.c)
headers = $(wildcard kernel/*.h drivers/*.h)
obj = ${c_sources:.c=.o}
all : os.img
run : all
		qemu-system-x86_64 -s -drive format=raw,file=os.img
os.img : boot/boot.img kernel/kernel.bin
		cat $^ > os.img
%.bin : kernel/kern_entry.o ${obj}
		ld -m elf_i386 -o $@ -Tkernel/kernel.ld $^ --oformat binary
%.o : %.c ${HEADERS}
		gcc -m32 -ffreestanding -fno-pic -c $< -o $@
%.o : %.asm
		nasm -f elf $< -o $@ 
%.img : boot/boot.com boot/boot2.com
		dd if=boot/boot.com of=$@ bs=512 count=1
		dd if=boot/boot2.com of=$@ bs=512 seek=1
%.com : %.asm
		nasm -f bin $< -I "boot/" -o $@
clean:
		rm -fr *.com *.o *.bin os.img *.dis 
		rm -fr kernel/*.o kernel/*.bin boot/*.com boot/*.img drivers/*.o
