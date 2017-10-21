all: linkedlist.c main.c
	gcc main.c linkedlist.c

run: all
	./a.out

clean:
	rm *.o
	rm *~
	rm a.out
