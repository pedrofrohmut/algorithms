fizzbuzz :: Int -> [String]
fizzbuzz n =
    let
        iterator :: Int -> [String]
        iterator i
            | i > n = []
            | mod i 15 == 0 = "FizzBuzz" : goNext
            | mod i 5 == 0 = "Buzz" : goNext
            | mod i 3 == 0 = "Fizz" : goNext
            | otherwise = (show i) : goNext
            where
                goNext = iterator (i + 1)
    in
        iterator 1

fizzbuzzMap :: Int -> [String]
fizzbuzzMap n =
    let
        fizzbuzzIt :: Int -> String
        fizzbuzzIt x
            | mod x 15 == 0 = "FizzBuzz"
            | mod x 5 == 0 = "Buzz"
            | mod x 3 == 0 = "Fizz"
            | otherwise = show x

    in
        map fizzbuzzIt [1..n]
