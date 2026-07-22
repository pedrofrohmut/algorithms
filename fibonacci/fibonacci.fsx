let fibonacci limit =
    let rec aux acc a b =
        let next = a + b in
        if next > limit then
            List.rev acc
        else
            aux (next :: acc) b next
    in
    aux [] 0 1

printfn "Fibonacci %A" (fibonacci 100)
