# Sorting Algorithms

list sorted alphabetically by algorithm name.

Results a taken by making a 10 tests sum and dividing it by 10.

* This is a Clang first repo others are here just as practice exercise

obs:

    All the programs to compile and run come from linux manjaro repos
    for C and Cpp is used gcc/g++ with -Ofast
    for Rust is used cargo run with --release
    for Python python3 and pypy3

## Bubble Sort 40k

- C          =   2,401ms (regular: 5,500ms, gains: +129%)
- CPP        =   5,151ms
- CSharp     =     499ms (dont know why it is so fast yet)
- javascript =   3,039ms
- cPython    = 212,344ms (almost 4 mins)
- Pypy       =   5,029ms
- Rust       =   2,632ms

## Insertion Sort 40k

- C          =    330ms
- CPP        =    309ms (vectors 390ms)
- javascript =    683ms
- cPython    = 92,213ms (1 and a half min)
- Pypy       =    581ms
- Rust       =    440ms

## MinMax Selection Sort 40k

- C = 528ms (regular: 1011ms, gains: +91%)

## Merge Sort 40k

- C          =  15ms (regular: 22ms, gains: +47%)
- CPP        =  11ms
- javascript =  38ms
- cPython    = 306ms
- Pypy       = 269ms

## Selection Sort 40k

- C          =   691ms
- CPP        =   682ms
- javascript = 1,630ms
- cPython    = 8,357ms
- Pypy       = 1,001ms
- Rust       =   968ms

## Swap Merge Sort 40k

- C = 9ms

## Swap Quick Sort

- C = 0ms (Too fast to measure?)

## Swap Selection Sort 40k

- C = 1011ms

# Searching Algorithms

## Linear Search 40k

- C = 605ms

## Binary Search 40k

- C = 4ms (same for while_loop and recursion)

## Quick Select 40k

- C = 16,159ms

--------------------------------------------------------------------------------

# How gains are calculated here

positive values for faster and negative for slower

gains = (regular / optimized) - 1

or

gains = (regular - optimized) / optimized

--------------------------------------------------------------------------------

# Algorithms Summary

    * Sorting
        * Bubble Sort
        * Insertion Sort
        * Merge Sort
        * MinMax Selection Sort
        * Selection Sort
        * Swap Merge Sort
        * Swap Quick Sort
        * Swap Selection Sort

    * Search
        * Binary Search
        * Linear Search
        * Quick Select

    * Data Structures
        * Binary Tree
        * Linked List
        * Queue
        * Stack

    * Others
        * Find Intersection of two arrays
        * Head/Tail Recursion

--------------------------------------------------------------------------------

# TODOS

1. Dijkstra's Algorithm
2. Hash Tables
3. Review 'Swap Merge Sort'

--------------------------------------------------------------------------------

# Source

1. Book: A Common-Sense Guide to Data Structures and Algorithms - Level up your
core programming skills by Jay Wengrow

--------------------------------------------------------------------------------

# Languages stuff for the curious one

languages in process: C, JavaScript, Python, Rust, Elixir, CSharp.

languages to future: Haskell, OCaml, Nim, Zig, Golang, Java, Kotlin, Clojure, Scala.

etc: Julia, Kotlin, Pascal, Dlang, Nim, Crystal.
