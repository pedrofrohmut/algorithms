let rec factorial n =
    if n < 2 then
        1
    else
        n * factorial (n - 1)

printfn "Factorial of %d is %d" 5 (factorial 5)
