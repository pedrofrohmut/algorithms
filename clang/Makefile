FLAGS=-std=c99 -Ofast

bubble: src/bubble-sort.c
	gcc -o out/bubble-sort.out ${FLAGS} src/bubble-sort.c lib/Arrays.c lib/Time.c

clean:
	rm -f out/*.out
	rm -f bin/*.o
