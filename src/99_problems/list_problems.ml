let err_msg = "Error: Your code sucks.";;

(*
  Tail of a List
  Beginner

  Write a function last : 'a list -> 'a option that returns the last element of a list

  # last ["a" ; "b" ; "c" ; "d"];;
  - : string option = Some "d"
  # last [];;
  - : 'a option = None
 *)

let rec last xs =
  match xs with
  | [] -> None
  | [x] -> Some x
  | _ :: rest -> last rest

let () =
  let err_msg = "Error. Your code sucks." in

  let result = last ["a" ; "b" ; "c" ; "d"] in
  if not (result = Some "d") then
    failwith err_msg;

  let result = last [] in
  if not (result = None) then
    failwith err_msg

let rec last2 = function
  | [] -> None
  | [x] -> Some x
  | _ :: tail -> last2 tail

(*
  Last Two Elements of a List
  Beginner

  Find the last two (last and penultimate) elements of a list.

  # last_two ["a"; "b"; "c"; "d"];;
  - : (string * string) option = Some ("c", "d")
  # last_two ["a"];;
  - : (string * string) option = None
*)

let rec last_two (xs: 'a list): ('a * 'a) option =
  match xs with
  | [] | [_] -> None
  | x :: y :: [] -> Some (x, y)
  | _ :: rest -> last_two rest

(*
  N'th Element of a List
  Beginner

  Find the N'th element of a list.

  # at 2 ["a"; "b"; "c"; "d"; "e"];;
  - : string option = Some "c"
  # at 2 ["a"];;
  - : string option = None

  Remark: OCaml has List.nth which numbers elements from 0 and raises an exception if the index is out of bounds.

  # List.nth ["a"; "b"; "c"; "d"; "e"] 2;;
  - : string = "c"
  # List.nth ["a"] 2;;
  Exception: Failure "nth".
*)

let at pos xs =
  let rec loop i pos xs =
    if i = pos then
      Some (List.hd xs)
    else
      loop (i + 1) pos (List.tl xs)
  in

  if pos >= List.length xs then
    None (* failwith "position out of bounds" *)
  else
    loop 0 pos xs

let () =
  let res = at 2 ["a"; "b"; "c"; "d"; "e"] in
  let expected = Some "c" in
  if res <> expected then
    failwith "Error: Your code sucks. `at` Case 1";

  let res = at 2 ["a"] in
  let expected = None in
  if res <> expected then
    failwith "Error: Your code sucks. `at` Case 2"


(* This function doesnt need auxiliar inner function *)
let rec at2 pos xs =
  match pos, xs with
  | _, [] -> None
  | 0, x :: _ -> Some x
  | n, _ :: tail -> at2 (n - 1) tail

let () =
  let res = at2 2 ["a"; "b"; "c"; "d"; "e"] in
  let expected = Some "c" in
  if res <> expected then
    failwith "Error: Your code sucks. `at` Case 1";

  let res = at2 2 ["a"] in
  let expected = None in
  if res <> expected then
    failwith "Error: Your code sucks. `at` Case 2"

(*
  Length of a List
  Beginner

  Find the number of elements of a list.

  OCaml standard library has List.length but we ask that you reimplement it.
  Bonus for a tail recursive solution.

  # length ["a"; "b"; "c"];;
  - : int = 3
  # length [];;
  - : int = 0
*)

let length xs =
  let rec loop i xs =
    match xs with
    | [] -> i
    | _ :: tail -> loop (i + 1) tail
  in
  loop 0 xs

let () =
  let msg = "Error. Your `length` code suck." in

  let res = length ["a"; "b"; "c"] in
  if not (res = 3) then
    failwith @@ msg ^ "case 1";

  let res = length [] in
  if not (res = 0) then
    failwith @@ msg ^ "case 2"
  else
    ()

(*
  Reverse a List
  Beginner

  Reverse a list.

  OCaml standard library has List.rev but we ask that you reimplement it.

  # rev ["a"; "b"; "c"];;
  - : string list = ["c"; "b"; "a"]
*)

let rev xs =
  let rec loop acc xs =
    match xs with
    | [] -> acc
    | x :: rest -> loop (x :: acc) rest
  in
  loop [] xs

let () =
  let msg = "Your code sucks. " in
  let res = rev ["a"; "b"; "c"] in
  if not (res = ["c"; "b"; "a"]) then
    failwith @@ msg ^ "Case 1"


(*
  Palindrome
  Beginner

  Find out whether a list is a palindrome.

  Hint: A palindrome is its own reverse.

  # is_palindrome ["x"; "a"; "m"; "a"; "x"];;
  - : bool = true
  # not (is_palindrome ["a"; "b"]);;
  - : bool = true
*)

type 'a palindrom_src =
  | String of string
  | Array of 'a array
  | List of 'a list

(* Polymorphic is_palindrome *)
let is_palindrome (src: 'a palindrom_src): bool =
  let is_not_equal low high src =
    match src with
    | String str -> String.get str low <> String.get str high
    | Array arr -> arr.(low) <> arr.(high)
    | List xs -> at low xs <> at high xs
  in

  let rec loop low high src =
    if low > high then
      true
    else if is_not_equal low high src then
      false
    else
      loop (low + 1) (high - 1) src
  in

  match src with
  | String str ->
     let low = 0 in
     let high = (String.length str) - 1 in
     loop low high src

  | Array arr ->
     let low = 0 in
     let high = (Array.length arr) - 1 in
     loop low high src

  | List xs ->
     let low = 0 in
     let high = (List.length xs) - 1 in
     loop low high src

let () =
  let msg = "Error. Your code sucks." in

  let res = is_palindrome (List ["x"; "a"; "m"; "a"; "x"]) in
  if res <> true then
    failwith @@ msg ^ "Case 1.1";

  let res = is_palindrome (Array [|"x"; "a"; "m"; "a"; "x"|]) in
  if res <> true then
    failwith @@ msg ^ "Case 1.2";

  let res = is_palindrome (String "xamax") in
  if res <> true then
    failwith @@ msg ^ "Case 1.3";

  let res = is_palindrome (List ["a"; "b"]) in
  if res <> false then
    failwith @@ msg ^ "Case 2.1";

  let res = is_palindrome (Array [|"a"; "b"|]) in
  if res <> false then
    failwith @@ msg ^ "Case 2.2";

  let res = is_palindrome (String "ab") in
  if res <> false then
      failwith @@ msg ^ "Case 2.3"

(*
  Flatten a List
  Intermediate

  Flatten a nested list structure.

  type 'a node =
  | One of 'a
  | Many of 'a node list

  # flatten [One "a"; Many [One "b"; Many [One "c" ;One "d"]; One "e"]];;
  - : string list = ["a"; "b"; "c"; "d"; "e"]
*)

type 'a node =
  | One of 'a
  | Many of 'a node list

let flatten xs =
  let rec loop acc xs =
    match xs with
    | [] ->
       acc

    | One x :: rest ->
       let new_acc = x :: acc in
       loop new_acc rest

    | Many ys :: rest ->
       let new_acc = loop acc ys in
       loop new_acc rest
  in
  List.rev (loop [] xs)

let () =
  let res = flatten [One "a"; Many [One "b"; Many [One "c" ;One "d"]; One "e"]] in
  let expected = ["a"; "b"; "c"; "d"; "e"] in
  if res <> expected then
    failwith "Error: Your code sucks. `flatten` Case 1"

(*
  Eliminate Duplicates
  Intermediate

  Eliminate consecutive duplicates of list elements.

  # compress ["a"; "a"; "a"; "a"; "b"; "c"; "c"; "a"; "a"; "d"; "e"; "e"; "e"; "e"];;
  - : string list = ["a"; "b"; "c"; "a"; "d"; "e"]
*)

let compress xs =
  let rec loop curr acc ys =
    match ys with
    | [] ->
       List.rev acc

    | y :: rest when y = curr ->
       loop curr acc rest

    | y :: rest ->
       loop y (y :: acc) rest
  in

  match xs with
  | [] -> []
  | x :: _ -> loop x [x] xs

let () =
  let res = compress ["a"; "a"; "a"; "a"; "b"; "c"; "c"; "a"; "a"; "d"; "e"; "e"; "e"; "e"] in
  let expected = ["a"; "b"; "c"; "a"; "d"; "e"] in
  if res <> expected then
    failwith "Error: Your code sucks. `compress` Case 1"

(*

  Pack Consecutive Duplicates
  Intermediate

  Pack consecutive duplicates of list elements into sublists.

  # pack ["a"; "a"; "a"; "a"; "b"; "c"; "c"; "a"; "a"; "d"; "d"; "e"; "e"; "e"; "e"];;
  - : string list list =
    [["a"; "a"; "a"; "a"]; ["b"]; ["c"; "c"]; ["a"; "a"]; ["d"; "d"]; ["e"; "e"; "e"; "e"]]
*)

let pack (xs: 'a list): 'a list list =
  let rec loop acc curr ys =
    match ys with
    | [] ->
       acc :: []

    | y :: rest when curr = y ->
       loop (y :: acc) curr rest

    | y :: _ ->
       acc :: loop [] y ys
  in

  match xs with
  | [] -> []
  | x :: _ -> loop [] x xs

let () =
  let result = pack ["a"; "a"; "a"; "a"; "b"; "c"; "c"; "a"; "a"; "d"; "d"; "e"; "e"; "e"; "e"] in
  let expected = [["a"; "a"; "a"; "a"]; ["b"]; ["c"; "c"]; ["a"; "a"]; ["d"; "d"]; ["e"; "e"; "e"; "e"]] in
  if result <> expected then
    failwith @@ err_msg ^ "`pack` Case 1"

(*
  Run-Length Encoding
  Beginner

  If you need to, refresh your memory about run-length encoding.

  Here is an example:

  # encode ["a"; "a"; "a"; "a"; "b"; "c"; "c"; "a"; "a"; "d"; "e"; "e"; "e"; "e"];;
  - : (int * string) list =
  [(4, "a"); (1, "b"); (2, "c"); (2, "a"); (1, "d"); (4, "e")]
*)

let encode (xs: 'a list): (int * 'a) list =
  let rec loop acc curr ys =
    match ys, acc with
    | [], _ ->
       acc :: []

    | y :: rest, (n, _)  when y = curr ->
       let new_acc = (n + 1), curr in
       loop new_acc curr rest

    | y :: rest, _ ->
       let next_acc = (1, y) in
       acc :: loop next_acc y rest
  in

  match xs with
  | [] -> []
  | x :: _ -> loop (0, x) x xs

let () =
  let result = encode ["a"; "a"; "a"; "a"; "b"; "c"; "c"; "a"; "a"; "d"; "e"; "e"; "e"; "e"] in
  let expected = [(4, "a"); (1, "b"); (2, "c"); (2, "a"); (1, "d"); (4, "e")] in
  if result <> expected then
    failwith @@ err_msg ^ "`enconde Case 1"

(*
  Modified Run-Length Encoding
  Beginner

  Modify the result of the previous problem in such a way that if an element has
  no duplicates it is simply copied into the result list. Only elements with
  duplicates are transferred as (N E) lists.

  Since OCaml lists are homogeneous, one needs to define a type to hold both
  single elements and sub-lists.

  type 'a rle =
  | One of 'a
  | Many of int * 'a

  # encode ["a"; "a"; "a"; "a"; "b"; "c"; "c"; "a"; "a"; "d"; "e"; "e"; "e"; "e"];;
  - : (int * string) list =
  [(4, "a"); (1, "b"); (2, "c"); (2, "a"); (1, "d"); (4, "e")]

  # modified_encode ["a"; "a"; "a"; "a"; "b"; "c"; "c"; "a"; "a"; "d"; "e"; "e"; "e"; "e"];;
  - : string rle list =
  [Many (4, "a"); One "b"; Many (2, "c"); Many (2, "a"); One "d"; Many (4, "e")]
*)

type 'a rle =
  | One of 'a
  | Many of int * 'a

let modified_encode (xs: 'a list): 'a rle list =
  let rec loop (ys: (int * 'a) list): 'a rle list =
    match ys with
    | [] -> []
    | (1, v) :: tail -> One v :: loop tail
    | (n, v) :: tail -> Many (n, v) :: loop tail
  in

  let encoded = encode xs in
  loop encoded

let () =
  let result = modified_encode ["a"; "a"; "a"; "a"; "b"; "c"; "c"; "a"; "a"; "d"; "e"; "e"; "e"; "e"] in
  let expected = [Many (4, "a"); One "b"; Many (2, "c"); Many (2, "a"); One "d"; Many (4, "e")] in
  if result <> expected then
    failwith @@ err_msg ^ "`modified_encode` Case 1"

(*
  Decode a Run-Length Encoded List
  Intermediate

  Given a run-length code list generated as specified in the previous problem, construct its uncompressed version.

  #  decode [Many (4, "a"); One "b"; Many (2, "c"); Many (2, "a"); One "d"; Many (4, "e")];;
  - : string list =
  ["a"; "a"; "a"; "a"; "b"; "c"; "c"; "a"; "a"; "d"; "e"; "e"; "e"; "e"]
*)

let rec decode (xs: 'a rle list): 'a list =
  if xs = [] then
    []

  else
    let head = List.hd xs in
    let tail = List.tl xs in

    match head with
    | One v -> v :: decode tail
    | Many (2, v) -> v :: decode (One v :: tail)
    | Many (n, v) -> v :: decode (Many (n - 1, v) :: tail)

let () =
  let result = decode [Many (4, "a"); One "b"; Many (2, "c"); Many (2, "a"); One "d"; Many (4, "e")] in
  let expected = ["a"; "a"; "a"; "a"; "b"; "c"; "c"; "a"; "a"; "d"; "e"; "e"; "e"; "e"] in
  if result <> expected then
    failwith @@ err_msg ^ "`decode` Case 1"

(*
  Run-Length Encoding of a List (Direct Solution)
  Intermediate

  Implement the so-called run-length encoding data compression method directly.
  I.e. don't explicitly create the sublists containing the duplicates, as in
  problem "Pack consecutive duplicates of list elements into sublists", but only
  count them. As in problem "Modified run-length encoding", simplify the result
  list by replacing the singleton lists (1 X) by X.

  # encode ["a";"a";"a";"a";"b";"c";"c";"a";"a";"d";"e";"e";"e";"e"];;
  - : string rle list =
  [Many (4, "a"); One "b"; Many (2, "c"); Many (2, "a"); One "d"; Many (4, "e")]
*)

let direct_encode (xs: 'a list):  'a rle list =
  let incr_acc acc =
    match acc with
    | One value -> Many (2, value)
    | Many (n, value) -> Many (n + 1, value)
  in

  let rec loop acc curr ys =
    match ys with
    | [] ->
       acc :: []

    | y :: rest when y = curr ->
       let new_acc = incr_acc acc in
       loop new_acc curr rest

    | y :: rest ->
       let next_acc = One y in
       acc :: loop next_acc y rest
  in

  match xs with
  | [] -> []
  | x :: rest -> loop (One x) x rest
