(* Tail recursion with accumulator no callstack unwind at base case reached *)
let fibonacci (limit: int): int list =
  let rec aux (acc: int list) (a: int) (b: int): int list =
    if b > limit then
      List.rev acc
    else
      aux (b :: acc) b (a + b)
  in
  aux [] 0 1

(* Simple recursion *)
let fibonacci2 (limit: int): int list =
  let rec aux (a: int) (b: int): int list =
    if b > limit then
      []
    else
      b :: aux b (a + b)
  in
  aux 0 1

let print_fibonacci (fibonacci_fun: int -> int list) (limit: int): unit =
  let sequence = fibonacci_fun limit in
  let sequence = List.map string_of_int sequence in
  let sequence = String.concat ", " sequence in
  Printf.printf "Fibonacci to %d is [ %s ]\n" limit sequence

let main (): unit =
  print_fibonacci fibonacci 1000;
  print_fibonacci fibonacci2 1000

let () = main ()
