# Makefile for building boot file

# Compiler and linker options
NASM = nasm
LD = ld
QEMU = qemu-system-x86_64

# Source file
SRC = boot.asm

# Output file
OUT = boot.bin

# Build target
all: $(OUT)

$(OUT): $(SRC)
	$(NASM) -f bin $(SRC) -o $(OUT)

run: $(OUT)
	$(QEMU) -fda $(OUT)

clean:
	rm -f $(OUT)