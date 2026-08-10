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

(*
  Determine Whether Two Positive Integer Numbers Are Coprime
  Beginner

  Determine whether two positive integer numbers are coprime.

  Two numbers are coprime if their greatest common divisor equals 1.

  # coprime 13 27;;
  - : bool = true
  # not (coprime 20536 7826);;
  - : bool = true
*)

let is_coprime: int -> int -> bool =
  fun a b -> gcd a b = 1
;;

let () =
  let res = is_coprime 13 27 in
  let exp = true in
  if res <> exp then
    failwith @@ err_msg ^ "`is_coprime` Case 1";

  let res = is_coprime 20536 7826 in
  let exp = false in
  if res <> exp then
    failwith @@ err_msg ^ "`is_coprime` Case 2"
;;

(*
  Calculate Euler's Totient Function Φ(m)
  Intermediate

  Euler's so-called totient function φ(m) is defined as the number of positive
  integers r (1 ≤ r < m) that are coprime to m. We let φ(1) = 1.

  Find out what the value of φ(m) is if m is a prime number. Euler's totient
  function plays an important role in one of the most widely used public key
  cryptography methods (RSA). In this exercise you should use the most primitive
  method to calculate this function (there are smarter ways that we shall discuss
  later).

  # phi 10;;
  - : int = 4
*)

let phi: int -> int = fun n ->

  let rec loop: int -> int -> int list = fun i n ->
    if i = n then
      []
    else if is_coprime i n then
      i :: loop (i + 1) n
    else
      loop (i + 1) n
  in

  let coprimes = loop 1 n in
  List.length coprimes
;;

let () =
  let res = phi 10 in
  let exp = 4 in
  if res <> exp then
    failwith @@ err_msg ^ "`phi` Case 1"
;;

  (*
  Determine the Prime Factors of a Given Positive Integer
  Intermediate

  Construct a flat list containing the prime factors in ascending order.

  # factors 315;;
  - : int list = [3; 3; 5; 7]
*)

let factors: int -> int list = fun n -> prime_factors n;;

let () =
  let res = factors 315 in
  let exp = [3; 3; 5; 7] in
  if res <> exp then
    failwith @@ err_msg ^ "`factors` Case 1"
;;

(*
  Determine the Prime Factors of a Given Positive Integer (2)
  Intermediate

  Construct a list containing the prime factors and their multiplicity.

  Hint: The problem is similar to problem Run-length encoding of a list
  (direct solution).

  # factors 315;;
  - : (int * int) list = [(3, 2); (5, 1); (7, 1)]
*)

let factors2: int -> (int * int) list = fun n ->

  let rec loop: int -> int * int -> int list -> (int * int) list = fun curr elem xs ->
    match xs, elem with
    | [], _ -> elem :: []

    | x :: xt, (v, n) ->
       if x = v then
         loop curr (v, n + 1) xt
       else
         elem :: loop x (x, 1) xt
  in

  match factors n with
  | [] -> []
  | x :: xt -> loop x (x, 1) xt
;;

let () =
  let res = factors2 315 in
  let exp = [(3, 2); (5, 1); (7, 1)] in
  if res <> exp then
    failwith @@ err_msg ^ "`factors2` Case 1"

(*
  Calculate Euler's Totient Function Φ(m) (Improved)
  Intermediate

  See problem "Calculate Euler's totient function φ(m)" for the definition of
  Euler's totient function. If the list of the prime factors of a number m is
  known in the form of the previous problem then the function phi(m) can be
  efficiently calculated as follows: Let [(p1, m1); (p2, m2); (p3, m3); ...] be
  the list of prime factors (and their multiplicities) of a given number m.
  Then φ(m) can be calculated with the following formula:

  phi(m) = (p1 - 1) * p1 ** (m1 - 1) * (p2 - 1) * p2 ** (m2 - 1) * (p3 - 1) * p3 ** (m3 - 1) * ...

  # phi_improved 10;;
  - : int = 4
  # phi_improved 13;;
  - : int = 12
*)

let phi_improved = fun n ->

  let rec loop = fun xs ->
    match xs with
    | [] -> 1.0
    | (p, m) :: xt ->
       let p = float_of_int p in
       let m = float_of_int m in
       let elem = (p -. 1.0) *. (p ** (m -. 1.0)) in
       elem *. loop xt
  in

  let prime_factors = factors2 n in

  match prime_factors with
  | [] -> failwith "TODO: unreacheable?"
  | _ -> int_of_float @@ loop prime_factors
;;

let () =
  let res = phi_improved 10 in
  let exp = 4 in
  if res <> exp then
    failwith @@ err_msg ^ "`phi_improved` Case 1";

  let res = phi_improved 13 in
  let exp = 12 in
  if res <> exp then
    failwith @@ err_msg ^ "`phi_improved` Case 2"
