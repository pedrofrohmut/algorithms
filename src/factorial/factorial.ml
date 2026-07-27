(* Run it with `$ ocaml factorial.ml` *)

(* Standard recursion *)
let rec factorial (n: int): int =
  if n < 0 then
    failwith "There is only factorial of positive integer numbers"
  else if n = 1 || n = 0 then
    1
  else
    n * factorial (n - 1)

(* Tail recursion with accumulator. Does not need to unwind the callstack at base case *)
let factorial2 (n: int): int =
  let inc (x: int): int = x + 1 in

  let rec factorial (acc: int) (i: int) (n: int): int =
    if i > n then
      acc
    else
      factorial (i * acc) (inc i) n
  in

  factorial 1 1 n

(* With mutable variable *)
let factorial3 (n: int): int =
  let result = ref 1 in
  for i = 1 to n do
    result := !result * i;
  done;
  !result

let print_factorial (factorial_fun: int -> int) (n: int): unit =
  for i = 1 to 10 do
    let result = factorial_fun i in
    Printf.printf "Factorial of %d is %d\n " i result
  done;
  print_endline ""

let main (): unit =
  print_factorial factorial 10;
  print_factorial factorial2 10;
  print_factorial factorial3 10

let () = main ()
