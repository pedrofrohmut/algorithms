let err_msg = "Error: Your code sucks.";;

(*
  Determine Whether a Given Integer Number Is Prime
  Intermediate

  Determine whether a given integer number is prime.

  # not (is_prime 1);;
  - : bool = true
  # is_prime 7;;
  - : bool = true
  # not (is_prime 12);;
  - : bool = true
*)

let is_prime: int -> bool = fun n ->
  let rec loop: int -> int -> bool = fun i n ->
    match n mod i with
    | 0 when i = n -> true
    | 0 -> false
    | _ -> loop (i + 1) n
  in

  if n < 2 then
    false
  else
    loop 2 n
;;

let () =
  let res = is_prime 1 in
  let exp = false in
  if res <> exp then
    failwith @@ err_msg ^ "`is_prime` Case 1";

  let res = is_prime 1 in
  let exp = false in
  if res <> exp then
    failwith @@ err_msg ^ "`is_prime` Case 1";

  let res = is_prime 1 in
  let exp = false in
  if res <> exp then
    failwith @@ err_msg ^ "`is_prime` Case 1"

(*
  Determine the Greatest Common Divisor of Two Positive Integer Numbers
  Intermediate

  Determine the greatest common divisor of two positive integer numbers.

  Use Euclid's algorithm.

  "The greatest common divisor of two numbers a and b is the product of the prime
  factors shared by the two numbers, where each prime factor can be repeated as
  many times as it divides both a and b.[8] For example, since 1386 can be factored
  into 2 × 3 × 3 × 7 × 11, and 3213 can be factored into 3 × 3 × 3 × 7 × 17, the
  GCD of 1386 and 3213 equals 63 = 3 × 3 × 7, the product of their shared prime
  factors (with 3 repeated since 3 × 3 divides both). If two numbers have no common
  prime factors, their GCD is 1 (obtained here as an instance of the empty product);
  in other words, they are coprime." Wikipedia

  https://en.wikipedia.org/wiki/Euclidean_algorithm

  # gcd 13 27;;
  - : int = 1
  # gcd 20536 7826;;
  - : int = 2
*)

let rec next_prime: int -> int -> int option = fun n limit ->
  if (n + 1) > limit then
    None
  else if is_prime (n + 1) then
    Some (n + 1)
  else
    next_prime (n + 1) limit
;;

let prime_factors: int -> int list = fun n ->
  let rec loop: int -> int -> int list = fun i n ->
    match n with
    | 1 -> []

    | x when x mod i = 0 ->
        i :: loop i (x / i)

    | _ ->
        match next_prime i n with
        | None -> failwith "Unreachable"
        | Some next_i -> loop next_i n
  in
  loop 2 n
;;

let elem_and_rest = fun x ys ->
  let rec loop acc x ys =
    match ys with
    | [] -> None, List.rev acc

    | y :: yt when y = x ->
        Some x, List.append (List.rev acc) yt

    | y :: yt ->
        loop (y :: acc) x yt
  in
  loop [] x ys
;;

let shared_factors: int list -> int list -> int list = fun xs ys ->

  let rec loop = fun xs ys ->
    match xs with
    | [] -> []
    | x :: xt ->
        let elem, rest = elem_and_rest x ys in
        match elem with
        | None -> loop xt ys
        | Some v -> v :: loop xt rest
  in

  loop xs ys
;;

let gcd: int -> int -> int = fun a b ->
  let a_factors = prime_factors a in
  let b_factors = prime_factors b in
  let shared = shared_factors a_factors b_factors in
  List.fold_left ( * ) 1 shared
;;
