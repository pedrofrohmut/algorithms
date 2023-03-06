FLAGS=-std=c99 -Ofast

# Flags:
# 	-std=c99 use c standard 99
# 	-Ofast tells compiler to use optimizations
#   -c Compile and assemble, but not link (creates object files)
#   -o Place output into a <file>

# Libs -------------------------------------------------------------------------

libs:
	gcc ${FLAGS} -c lib/Arrays.c -o bin/Arrays.o
	gcc ${FLAGS} -c lib/Time.c -o bin/Time.o

arrays: lib/Arrays.c
	gcc ${FLAGS} -c lib/Arrays.c -o bin/Arrays.o

time: lib/Time.c
	gcc ${FLAGS} -c lib/Time.c -o bin/Time.o

# Sort -------------------------------------------------------------------------

bubble: src/bubble-sort.c
	gcc ${FLAGS} src/bubble-sort.c bin/Arrays.o bin/Time.o -o out/bubble-sort.out

insertion: src/insertion-sort.c
	gcc ${FLAGS} src/insertion-sort.c bin/Arrays.o bin/Time.o -o out/insertion-sort.out

minmax-selection: src/minmax-selection-sort.c
	gcc ${FLAGS} src/minmax-selection-sort.c bin/Arrays.o bin/Time.o -o out/minmax-selection-sort.out

merge: src/merge-sort.c
	gcc ${FLAGS} src/merge-sort.c bin/Arrays.o bin/Time.o -o out/merge-sort.out

selection: src/selection-sort.c
	gcc ${FLAGS} src/selection-sort.c bin/Arrays.o bin/Time.o -o out/selection-sort.out

swap-quick: src/swap-quick-sort.c
	gcc ${FLAGS} src/swap-quick-sort.c bin/Arrays.o bin/Time.o -o out/swap-quick-sort.out

swap-selection: src/swap-selection-sort.c
	gcc ${FLAGS} src/swap-selection-sort.c bin/Arrays.o bin/Time.o -o out/swap-selection-sort.out

# Search -----------------------------------------------------------------------

linear: src/linear-search.c
	gcc ${FLAGS} src/linear-search.c bin/Arrays.o bin/Time.o -o out/linear-search.out

binary: src/binary-search.c
	gcc ${FLAGS} src/binary-search.c bin/Arrays.o bin/Time.o -o out/binary-search.out

# Others -----------------------------------------------------------------------

find-intersection: src/find-intersection.c
	gcc ${FLAGS} src/find-intersection.c bin/Arrays.o bin/Time.o -o out/find-intersection.out


clean: # -f for no output or prompt
	rm -f out/*.out
	rm -f bin/*.o
