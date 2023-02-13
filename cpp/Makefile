FLAGS=-std=c++20 -Ofast

# Libs -------------------------------------------------------------------------

libs:
	gcc -c lib/Arrays.cpp -o bin/Arrays.o
	gcc -c lib/Time.cpp -o bin/Time.o

arrays: lib/Arrays.c
	gcc -c lib/Arrays.cpp -o bin/Arrays.o

time: lib/Time.c
	gcc -c lib/Time.cpp -o bin/Time.o

# Mains ------------------------------------------------------------------------

bubble: src/bubble-sort.cpp
	g++ -o out/bubble-sort.out ${FLAGS} src/bubble-sort.cpp bin/Arrays.o bin/Time.o

insertion: src/insertion-sort.cpp
	g++ -o out/insertion-sort.out ${FLAGS} src/insertion-sort.cpp bin/Arrays.o bin/Time.o

merge: src/merge-sort.cpp
	g++ -o out/merge-sort.out ${FLAGS} src/merge-sort.cpp bin/Arrays.o bin/Time.o

selection: src/selection-sort.cpp
	g++ -o out/selection-sort.out ${FLAGS} src/selection-sort.cpp bin/Arrays.o bin/Time.o

clean:
	rm -f out/*.out
	rm -f bin/*.o
