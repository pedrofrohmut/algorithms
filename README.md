# Sorting Algorithms

list sorted alphabetically by algorithm name.

Results a taken by making a 10 tests sum and dividing it by 10.

Some has 2 different results because left is (old) sort on shuffled array of 1..N
and the second is (new) sort on random numbers (rng: 0, INT_MAX).

## Bubble Sort 40k

- C = 2,401ms (regular: 5,500ms, gains: +129%)
- CPP = 5,151ms
- javascript = 3,039ms
- cPython = 212,344ms (almost 4 mins)
- Pypy = 5,029ms

## Insertion Sort 40k

- C = 373ms
- CPP = 309ms
- javascript = 683ms
- cPython = 92,213ms (1 and a half min)
- Pypy = 581ms

## MinMax Selection Sort 40k

- C = 528ms (regular: 1011ms, gains: +91%)

## Merge Sort 40k

- C = 15ms (regular: 22ms, gains: +47%)
- CPP = 11ms
- javascript = 38ms
- cPython = 306ms
- Pypy = 269ms

## Selection Sort 40k

- C = 691ms
- CPP = 682ms
- javascript = 1,630ms
- cPython = 8,357ms
- Pypy = 1,001ms

## Swap Selection Sort 40k

- C = 1011ms

# Searching Algorithms

## Linear Search 40k

- C = 605ms

## Binary Search 40k

- C = 4ms (same for while_loop and recursion)

--------------------------------------------------------------------------------

# How gains are calculated here

positive values for faster and negative for slower

gains = (regular / optimized) - 1

or

gains = (regular - optimized) / optimized

--------------------------------------------------------------------------------

languages in process: C, JavaScript, Python, Rust, Elixir, CSharp.

languages to future: Haskell, OCaml, Nim, Zig, Golang, Java, Kotlin, Clojure.

etc: Julia, Kotlin, Pascal, Dlang.
