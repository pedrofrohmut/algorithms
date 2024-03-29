FLAGS=-std=c99 -Ofast

# Flags:
# 	-std=c99 use c standard 99
# 	-Ofast tells compiler to use optimizations
#   -c Compile and assemble, but not link (creates object files)
#   -o Place output into a <file>

# Libs -------------------------------------------------------------------------

arrays-lib: lib/Arrays.c
	gcc ${FLAGS} -c lib/Arrays.c -o bin/Arrays.o

time-lib: lib/Time.c
	gcc ${FLAGS} -c lib/Time.c -o bin/Time.o

linked-list-lib: lib/LinkedList.c
	gcc ${FLAGS} -c lib/LinkedList.c -o bin/LinkedList.o

queue-lib: lib/Queue.c
	gcc ${FLAGS} -c lib/Queue.c -o bin/Queue.o

stack-lib: lib/Stack.c
	gcc ${FLAGS} -c lib/Stack.c -o bin/Stack.o

binary-tree-lib: lib/BinaryTree.c
	gcc ${FLAGS} -c lib/BinaryTree.c -o bin/BinaryTree.o

libs: arrays-lib time-lib linked-list-lib queue-lib stack-lib binary-tree-lib

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

swap-merge-sort: src/swap-merge-sort.c
	gcc ${FLAGS} src/swap-merge-sort.c bin/Arrays.o bin/Time.o -o out/swap-merge-sort.out

swap-quick: src/swap-quick-sort.c
	gcc ${FLAGS} src/swap-quick-sort.c bin/Arrays.o bin/Time.o -o out/swap-quick-sort.out

swap-selection: src/swap-selection-sort.c
	gcc ${FLAGS} src/swap-selection-sort.c bin/Arrays.o bin/Time.o -o out/swap-selection-sort.out

# Search -----------------------------------------------------------------------

linear: src/linear-search.c
	gcc ${FLAGS} src/linear-search.c bin/Arrays.o bin/Time.o -o out/linear-search.out

binary: src/binary-search.c
	gcc ${FLAGS} src/binary-search.c bin/Arrays.o bin/Time.o -o out/binary-search.out

quick-select: src/quick-select.c
	gcc ${FLAGS} src/quick-select.c bin/Arrays.o bin/Time.o -o out/quick-select.out


# Data Structures --------------------------------------------------------------

binary-tree: binary-tree-lib src/binary-tree.c
	gcc ${FLAGS} src/binary-tree.c bin/BinaryTree.o -o out/binary-tree.out

linked-list: linked-list-lib src/linked-list.c
	gcc ${FLAGS} src/linked-list.c bin/LinkedList.o -o out/linked-list.out

queue: queue-lib src/queue.c
	gcc ${FLAGS} src/queue.c bin/Queue.o -o out/queue.out

stack: stack-lib src/stack.c
	gcc ${FLAGS} src/stack.c bin/Stack.o -o out/stack.out

# Others -----------------------------------------------------------------------

find-intersection: src/find-intersection.c
	gcc ${FLAGS} src/find-intersection.c bin/Arrays.o bin/Time.o -o out/find-intersection.out


clean: # -f for no output or prompt
	rm -f out/*.out
	rm -f bin/*.o
