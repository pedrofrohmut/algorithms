FLAGS=-std=c99 -Ofast

bubble: src/bubble-sort.c
	gcc -o out/bubble-sort.out ${FLAGS} src/bubble-sort.c lib/Arrays.c lib/Time.c

insertion: src/insertion-sort.c
	gcc -o out/insertion-sort.out ${FLAGS} src/insertion-sort.c lib/Arrays.c lib/Time.c

merge: src/merge-sort.c
	gcc -o out/merge-sort.out ${FLAGS} src/merge-sort.c lib/Arrays.c lib/Time.c

selection: src/selection-sort.c
	gcc -o out/selection-sort.out ${FLAGS} src/selection-sort.c lib/Arrays.c lib/Time.c

clean:
	rm -f out/*.out
	rm -f bin/*.o
