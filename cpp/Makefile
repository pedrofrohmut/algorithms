FLAGS=-std=c++20 -Ofast

insertion: src/insertion-sort.cpp
	g++ -o out/insertion-sort.out ${FLAGS} src/insertion-sort.cpp lib/Arrays.cpp lib/Time.cpp

clean:
	rm -f out/*.out
	rm -f bin/*.o
