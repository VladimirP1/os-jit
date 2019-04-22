OUT=out

all:
	mkdir -p out

	$(CC) fnv32.c -nostdlib -static -fPIC -o $(OUT)/code.elf
	objcopy $(OUT)/code.elf --dump-section .text=$(OUT)/code.bin
	./xor.py $(OUT)/code.bin $(OUT)/code_xor.bin $(KEY)
	cd $(OUT) && xxd -i code_xor.bin > code_xor.h && cd -

clean:
	rm -rf $(OUT)

.PHONY: all clean

