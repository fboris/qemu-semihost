all:
	@echo "Please execute ./test_semihost.sh"

clean:
	rm -f hello.elf

distclean: clean
	rm -rf qemu/build
