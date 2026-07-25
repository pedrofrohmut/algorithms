(*
  prime-numbers.ml
  Pedro Frohmut 2026 Copyrights

  Get all the prime numbers up to a limit (positive integer)

  Extra: Use the list of primes to check the next primes. All numbers are divisible
  by prime numbers, so checking the other numbers are a waste of cycles.
 *)

let inc (n: int): int = n + 1
let dec (n: int): int = n - 1

(* Is prime with recursion.
   - The best performance.
   Tail call optimized and returns as soon as condition is met *)
let is_prime (n: int): bool =
    let rec loop i n =
      if i = n then
        true
      else if n mod i = 0 then
        false
      else
        loop (inc i) n
    in
    loop 2 n

(* Is prime with a loop and bool ref but there is not early return in the loop and
   the loop always goes full iteration every time.
   - The worst performance.
   Always runs the whole loop and must allocate a ref.*)
let is_prime2 (n: int): bool =
  let result = ref true in
  for i = 2 to (n - 1) do
    if n mod i = 0 then
      result := false
  done;
  !result

(* Early returns in the loop using try/raise
   - The medium performance.
   It returns early when the condition is met but it has the exception overhead to
 deal with (Exceptions are heavy). *)
let is_prime3 (n: int): bool =
  try
    for i = 2 to (n - 1) do
      if n mod i = 0 then
        raise Exit
    done;
    true
  with Exit -> false

let primes (is_prime_fun: int -> bool) (limit: int): int list =
  let rec primes (acc: int list) (i: int): int list =
    if i < 2 then
      acc
    else
      if is_prime_fun i then
        primes (i :: acc) (dec i)
      else
        primes acc (dec i)
  in

  if limit < 2 then
    failwith "The smaller prime number is 2"
  else
    primes [] (dec limit)

let print_list (label: string) (xs: int list): unit =
  let str_list = xs |> List.map string_of_int |> String.concat ", " in
  Printf.printf "%s => [%s]\n" label str_list

let main (): unit =
  print_list "is_prime_1 recursion     " (primes is_prime 100);
  print_list "is_prime_2 ref+loop      " (primes is_prime2 100);
  print_list "is_prime_3 exception+loop" (primes is_prime2 100)

let () = main ()
