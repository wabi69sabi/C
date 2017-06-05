GCC:
	gcc -c converter.c

LINK: GCC
	gcc -o converter converter.o

clean:
	rm -f converter.o converter

run: LINK
	./converter

all: clean LINK run
