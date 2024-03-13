ASM = nasm
CC = gcc
BOOTSTRAP_FILE = Assembly/bootstrap.asm 
INIT_KERNEL_FILES = Assembly/starter.asm
KERNEL_FILES = main.cpp
KERNEL_FLAGS = -Wall -m32 -c -ffreestanding -fno-asynchronous-unwind-tables -fno-pie -lstdc++
KERNEL_OBJECT = -o kernel.elf

build: $(BOOTSTRAP_FILE) $(KERNEL_FILE)
	$(ASM) -f bin $(BOOTSTRAP_FILE) -o bootstrap.o
	$(ASM) -f elf32 $(INIT_KERNEL_FILES) -o starter.o 
	$(CC) $(KERNEL_FLAGS) $(KERNEL_FILES) $(KERNEL_OBJECT)
	ld -melf_i386 -Tlinker.ld starter.o kernel.elf -o HYDRIXOSKERNEL.elf
	objcopy -O binary HYDRIXOSKERNEL.elf HYDRIXOSKERNEL.bin
	dd if=bootstrap.o of=HYDRIXOS.img
	dd seek=1 conv=sync if=HYDRIXOSKERNEL.bin of=HYDRIXOS.img bs=512 count=5
	dd seek=6 conv=sync if=/dev/zero of=HYDRIXOS.img bs=512 count=2046
	qemu-system-i386 -s HYDRIXOS.img

clean:
	rm -f *.o *.bin *.elf