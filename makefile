all: rand_things.c
	make clean
	gcc rand_things.c

run: rand_things.c
	make clean
	gcc rand_things.c
	./a.out

clean:
	touch arrayhere
	rm arrayhere
	rm *~
	rm *#
	rm a.out
