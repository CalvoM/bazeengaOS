c_sources = $(wildcard kernel/*.c drivers/*.c cpu/*.c shell/*.c)
headers = $(wildcard kernel/*.h drivers/*.h cpu/*.h shell/*.h)
obj = ${c_sources:.c=.o cpu/interrupts.o}
.PHONY : clean
all : os.img
run : all
		qemu-system-x86_64 -s -drive format=raw,file=os.img
os.img : boot/boot.img kernel/kernel.bin
		dd if=/dev/zero of=temp.bin bs=511 count=10
		cat $^ > os.img
		cat temp.bin >> os.img #pad the img file to enable getting sectors to save process of changing boot/boot2.asm:17 all time when kernel grows
		rm temp.bin
kernel/kernel.bin : kernel/kern_entry.o ${obj}
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
		rm -fr *.com *.o *.bin os.img *.dis kernel/*.o kernel/*.bin boot/*.com boot/*.img drivers/*.o cpu/*.o
