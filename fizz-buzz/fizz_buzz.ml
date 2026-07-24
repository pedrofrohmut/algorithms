(*
  fizz_buzz.ml
  Pedro Frohmut 2026 Copyrights

  Fizz Buzz algorithm: it returns Fizz to multiple of 3, Buzz to multiple of 5 and
  FizzBuzz when it is multiple of 3 and 5.
 *)

(* TODO: make a fizz buzz with a custom type instead of just strings *)
(* Regular recursion with callstack unwinding at the end *)
let fizz_buzz (limit: int): string list =
  let rec fizz_buzz (limit: int): string list =
    match limit with
    | x when x < 0 -> failwith "Fizz Buzz only support positive integer numbers"
    | 0 -> []
    | x when x mod 15 == 0 -> "FizzBuzz" :: fizz_buzz (limit - 1)
    | x when x mod 5 == 0  -> "Buzz" :: fizz_buzz (limit - 1)
    | x when x mod 3 == 0  -> "Fizz" :: fizz_buzz (limit - 1)
    | x -> string_of_int x :: fizz_buzz (limit - 1)
  in
  List.rev (fizz_buzz limit)

(* Tail call recursion with accumulator, counter and without callstack unwinding
   when the base case is reached *)
let fizz_buzz2 (limit: int): string list =
  let rec aux (acc: string list) (counter: int) (limit: int): string list =
    match counter with
    | i when i < 0 -> failwith "Fizz Buzz only support positive integer numbers"
    | i when i > limit -> acc
    | i when i mod 15 == 0 -> aux ("FizzBuzz" :: acc) (i + 1) limit
    | i when i mod 5 == 0  -> aux ("Buzz" :: acc) (i + 1) limit
    | i when i mod 3 == 0  -> aux ("Fizz" :: acc) (i + 1) limit
    | i -> aux (string_of_int i :: acc) (i + 1) limit
  in
  List.rev (aux [] 1 limit)

type fizz_buzz_type =
  | Fizz
  | Buzz
  | FizzBuzz
  | JustNumber of int

(* Creates a list of fizz buzz using the custom type *)
let fizz_buzz3 (limit: int): fizz_buzz_type list =
  let rec aux (acc: fizz_buzz_type list) (counter: int) (limit: int): fizz_buzz_type list =
    match counter with
    | i when i > limit -> acc
    | i when i mod 15 == 0 -> aux (FizzBuzz :: acc) (i + 1) limit
    | i when i mod 5 == 0 -> aux (Buzz :: acc) (i + 1) limit
    | i when i mod 3 == 0 -> aux (Fizz :: acc) (i + 1) limit
    | i -> aux (JustNumber i :: acc) (i + 1) limit
  in
  if limit < 0 then
    failwith "Fizz Buzz only support positive integer numbers"
  else
    List.rev (aux [] 1 limit)

(* Prints a Fizz Buzz Type list *)
let fizz_buzz_printer2 (limit: int): unit =
  let string_of_fizz_buzz_type (typ: fizz_buzz_type): string  =
    match typ with
    | Fizz -> "Fizz"
    | Buzz -> "Buzz"
    | FizzBuzz -> "FizzBuzz"
    | JustNumber x -> string_of_int x
  in
  let seq =
    fizz_buzz3 limit
    |> List.map (fun x -> string_of_fizz_buzz_type x)
    |> String.concat ", "
  in
  Printf.printf "FizzBuzz => [%s]\n" seq

let fizz_buzz_printer (fizz_buzz_fun: int -> string list) (limit: int): unit =
  let seq = fizz_buzz_fun limit |> String.concat ", " in
  let out = Printf.sprintf "FizzBuzz => [%s]" seq in
  print_endline out

let main (): unit =
  fizz_buzz_printer fizz_buzz 100;
  fizz_buzz_printer fizz_buzz2 100;
  fizz_buzz_printer2 100

let () =
  main ()
