FLAGS=-std=c99 -Ofast

# Libs -------------------------------------------------------------------------

libs:
	gcc -c lib/Arrays.c -o bin/Arrays.o
	gcc -c lib/Time.c -o bin/Time.o

arrays: lib/Arrays.c
	gcc -c lib/Arrays.c -o bin/Arrays.o

time: lib/Time.c
	gcc -c lib/Time.c -o bin/Time.o

# Sort -------------------------------------------------------------------------

bubble: src/bubble-sort.c
	gcc -o out/bubble-sort.out ${FLAGS} src/bubble-sort.c bin/Arrays.o bin/Time.o

insertion: src/insertion-sort.c
	gcc -o out/insertion-sort.out ${FLAGS} src/insertion-sort.c bin/Arrays.o bin/Time.o

minmax-selection: src/minmax-selection-sort.c
	gcc -o out/minmax-selection-sort.out ${FLAGS} src/minmax-selection-sort.c bin/Arrays.o bin/Time.o

merge: src/merge-sort.c
	gcc -o out/merge-sort.out ${FLAGS} src/merge-sort.c bin/Arrays.o bin/Time.o

selection: src/selection-sort.c
	gcc -o out/selection-sort.out ${FLAGS} src/selection-sort.c bin/Arrays.o bin/Time.o

# Search -----------------------------------------------------------------------

linear: src/linear-search.c
	gcc -o out/linear-search.out ${FLAGS} src/linear-search.c bin/Arrays.o bin/Time.o

clean:
	rm -f out/*.out
	rm -f bin/*.o
