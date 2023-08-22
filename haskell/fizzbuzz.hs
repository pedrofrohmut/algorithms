fizzbuzz :: Int -> [String]
fizzbuzz n =
    let
        helper :: Int -> Int -> [String]
        helper num i
            | i > n = []
            | mod i 15 == 0 = "FizzBuzz" : goNext
            | mod i 5 == 0 = "Buzz" : goNext
            | mod i 3 == 0 = "Fizz" : goNext
            | otherwise = (show i) : goNext
            where
                goNext = helper n (i + 1)
    in
        helper n 1
