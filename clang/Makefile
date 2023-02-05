FLAGS=-std=c99 -Ofast

insertion: src/insertion-sort.c
	gcc -o out/insertion-sort.out ${FLAGS} src/insertion-sort.c lib/Arrays.c lib/Time.c

bubble: src/bubble-sort.c
	gcc -o out/bubble-sort.out ${FLAGS} src/bubble-sort.c lib/Arrays.c lib/Time.c

clean:
	rm -f out/*.out
	rm -f bin/*.o
