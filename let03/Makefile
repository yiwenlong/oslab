mbr.img: mbr.S
	gcc -ggdb -c $<
	ld mbr.o -Ttext 0x7c00
	objcopy -S -O binary -j .text a.out $@

run: mbr.img
	qemu-system-x86_64 $<

clean: 
	rm -f *.img *.o a.out
