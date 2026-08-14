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

(*
  Duplicate the Elements of a List
  Beginner

  Duplicate the elements of a list.

  # duplicate ["a"; "b"; "c"; "c"; "d"];;
  - : string list = ["a"; "a"; "b"; "b"; "c"; "c"; "c"; "c"; "d"; "d"]
*)

let rec duplicate ys =
  match ys with
  | [] -> []
  | x :: tail -> x :: x :: duplicate tail

let () =
  let result = duplicate ["a"; "b"; "c"; "c"; "d"] in
  let expected = ["a"; "a"; "b"; "b"; "c"; "c"; "c"; "c"; "d"; "d"] in
  if result <> expected then
    failwith @@ err_msg ^ "`duplicate` Case 1"

(*
  Replicate the Elements of a List a Given Number of Times
  Intermediate

  Replicate the elements of a list a given number of times.

  # replicate ["a"; "b"; "c"] 3;;
  - : string list = ["a"; "a"; "a"; "b"; "b"; "b"; "c"; "c"; "c"]
*)

let replicate xs n =
  let rec loop ys i n =
    match ys, i with
    | [], _ -> []

    | y :: tail, 1 ->
       y :: loop tail n n

    | y :: _, _ ->
       y :: loop ys (i - 1) n
  in
  loop xs n n

let () =
  let result = replicate ["a"; "b"; "c"] 3 in
  let expected = ["a"; "a"; "a"; "b"; "b"; "b"; "c"; "c"; "c"] in
  if result <> expected then
    failwith @@ err_msg ^ "`replicate` Case 1"

(*
  Drop Every N'th Element From a List
  Intermediate

  Drop every N'th element from a list.

  # drop ["a"; "b"; "c"; "d"; "e"; "f"; "g"; "h"; "i"; "j"] 3;;
  - : string list = ["a"; "b"; "d"; "e"; "g"; "h"; "j"]
*)

let rec drop (xs: 'a list) (n: int): 'a list =
  match xs, n with
  | [], _ -> []
  | _, 0 -> xs
  | head :: tail, _ -> drop tail (n - 1)

(*
  Split a List Into Two Parts; The Length of the First Part Is Given
  Beginner

  Split a list into two parts; the length of the first part is given.

  If the length of the first part is longer than the entire list, then the first
  part is the list and the second part is empty.

  # split ["a"; "b"; "c"; "d"; "e"; "f"; "g"; "h"; "i"; "j"] 3;;
  - : string list * string list = (["a"; "b"; "c"], ["d"; "e"; "f"; "g"; "h"; "i"; "j"])

  # split ["a"; "b"; "c"; "d"] 5;;
  - : string list * string list = (["a"; "b"; "c"; "d"], [])
*)

let split (xs: 'a list) (n: int): 'a list * 'a list =
  let rec loop acc i ys =
    match ys, i with
    | [], _ -> List.rev acc, []
    | _, 0 -> List.rev acc, ys
    | y :: tail, _ -> loop (y :: acc) (i - 1) tail
  in
  loop [] n xs

let () =
  let result =  split ["a"; "b"; "c"; "d"; "e"; "f"; "g"; "h"; "i"; "j"] 3 in
  let expected = (["a"; "b"; "c"], ["d"; "e"; "f"; "g"; "h"; "i"; "j"]) in
  if result <> expected then
    failwith @@ err_msg ^ "`split` Case 1";

  let result = split ["a"; "b"; "c"; "d"] 5 in
  let expected = (["a"; "b"; "c"; "d"], []) in
  if result <> expected then
    failwith @@ err_msg ^ "`split` Case 2"

(*
  Extract a Slice From a List
  Intermediate

  Given two indices, i and k, the slice is the list containing the elements
  between the i'th and k'th element of the original list (both limits included).
  Start counting the elements with 0 (this is the way the List module numbers
  elements).

  # slice ["a"; "b"; "c"; "d"; "e"; "f"; "g"; "h"; "i"; "j"] 2 6;;
  - : string list = ["c"; "d"; "e"; "f"; "g"]
*)

let rec slice (xs: 'a list) (low: int) (high: int): 'a list =
  match xs, low, high with
  | [], _, _ -> []
  | x :: _, 0, 0 -> x :: []
  | x :: tail, 0, _ -> x :: slice tail 0 (high - 1)
  | _ :: tail, _, _ -> slice tail (low - 1) (high - 1)

let () =
  let result = slice ["a"; "b"; "c"; "d"; "e"; "f"; "g"; "h"; "i"; "j"] 2 6 in
  let expected = ["c"; "d"; "e"; "f"; "g"] in
  if result <> expected then
    failwith @@ err_msg ^ "`slice` Case 1"

(*
  Rotate a List N Places to the Left
  Intermediate

  Rotate a list N places to the left.

  # rotate ["a"; "b"; "c"; "d"; "e"; "f"; "g"; "h"] 3;;
  - : string list = ["d"; "e"; "f"; "g"; "h"; "a"; "b"; "c"]
*)

let rotate (xs: 'a list) (n: int): 'a list =
  let rec loop acc i ys =
    match ys, i with
    | [], _ | _, 0 ->
       List.rev acc, ys

    | y :: tail, _ ->
       loop (y :: acc) (i - 1) tail
  in
  let rotation_slice, rest = loop [] n xs in
  List.append rest rotation_slice

let () =
  let result = rotate ["a"; "b"; "c"; "d"; "e"; "f"; "g"; "h"] 3 in
  let expected = ["d"; "e"; "f"; "g"; "h"; "a"; "b"; "c"] in
  if result <> expected then
    failwith @@ err_msg ^ "`rotate` Case 1"

(*
  Remove the K'th Element From a List
  Beginner

  Remove the K'th element from a list.

  The first element of the list is numbered 0, the second 1,...

  # remove_at 1 ["a"; "b"; "c"; "d"];;
  - : string list = ["a"; "c"; "d"]
*)

let rec remove_at (pos: int) (xs: 'a list): 'a list =
  match xs, pos with
  | [], _ -> []
  | _ :: tail, 0 -> tail
  | x :: tail, _ -> x :: remove_at (pos - 1) tail

let () =
  let result = remove_at 1 ["a"; "b"; "c"; "d"] in
  let expected = ["a"; "c"; "d"] in
  if result <> expected then
    failwith @@ err_msg ^ "`remove_at` Case 1"

(*
  Insert an Element at a Given Position Into a List
  Beginner

  Start counting list elements with 0. If the position is larger or equal to the
  length of the list, insert the element at the end. (The behavior is unspecified
  if the position is negative.)

  # insert_at "alfa" 1 ["a"; "b"; "c"; "d"];;
  - : string list = ["a"; "alfa"; "b"; "c"; "d"]
*)

let rec insert_at (elem: 'a) (pos: int) (xs: 'a list): 'a list =
  match xs, pos with
  | [], _ -> []
  | x :: tail, 0 -> elem :: x :: tail
  | x :: tail, _ -> x :: insert_at elem (pos - 1) tail

let () =
  let result = insert_at "alfa" 1 ["a"; "b"; "c"; "d"] in
  let expected = ["a"; "alfa"; "b"; "c"; "d"] in
  if result <> expected then
    failwith @@ err_msg ^ "`insert_at` Case 1"

(*
  Create a List Containing All Integers Within a Given Range
  Beginner

  If first argument is greater than second, produce a list in decreasing order.

  # range 4 9;;
  - : int list = [4; 5; 6; 7; 8; 9]
*)

let rec range (low: int) (high: int): int list =
  match low, high with
  | l, h when  l = h -> l :: []
  | l, _ -> l :: range (low + 1) high


let () =
  let result = range 4 9 in
  let expected = [4; 5; 6; 7; 8; 9] in
  if result <> expected then
    failwith @@ err_msg ^ "`range` Case 1"

(*
  Extract a Given Number of Randomly Selected Elements From a List
  Intermediate

  The selected items shall be returned in a list. We use the Random module and
  initialise it with Random.init 0 at the start of the function for
  reproducibility and validate the solution. To make the function truly random,
  however, one should remove the call to Random.init 0

  # rand_select ["a"; "b"; "c"; "d"; "e"; "f"; "g"; "h"] 3;;
  - : string list = ["e"; "c"; "g"]
*)

let rand_select (xs: 'a list) (amount: int): 'a list =
  let rec get_at i ys =
    match ys, i with
    | [], _ -> None
    | y :: _, 0 -> Some y
    | _ :: tail, _ -> get_at (i - 1) tail
  in

  let rec loop amt ys =
    if amt = 0 then
      []
    else
      let min = 0 in
      let max = (List.length ys) - 1 in
      let pos = Random.int_in_range ~min ~max in
      let elem =
        match get_at pos ys with
        | None -> failwith "Out of bounds"
        | Some e -> e
      in
      elem :: loop (amt - 1) ys
  in

  Random.init 0;
  loop 3 xs

(*
  Lotto: Draw N Different Random Numbers From the Set 1..M
  Beginner

  Draw N different random numbers from the set 1..M.

  The selected numbers shall be returned in a list.

  Numbers from random.init 0: min:1 max:49 [29; 4; 20; 35; 24; 19; 30; 44; 33]

  # lotto_select 6 49;;
  - : int list = [20; 28; 45; 16; 24; 38]
 *)

let lotto_select (amount: int) (min: int) (max: int): int list =
  let rec loop n min max =
    if n = 0 then
      []
    else
      let rnd_num = Random.int_in_range ~min ~max in
      rnd_num :: loop (n - 1) min max
  in

  Random.init 0;
  loop amount min max
;;

let () =
  let result = lotto_select 6 1 49 in
  let expected = [29; 4; 20; 35; 24; 19] in
  if result <> expected then
    failwith @@ err_msg ^ "`lotto_select` Case 1";

  let result = lotto_select 9 1 49 in
  let expected = [29; 4; 20; 35; 24; 19; 30; 44; 33] in
  if result <> expected then
    failwith @@ err_msg ^ "`lotto_select` Case 2"
;;

(*
  Generate a Random Permutation of the Elements of a List
  Beginner

  Generate a random permutation of the elements of a list.

  Random responses: [0; 4; 3; 0; 0; 0]
  (Random.init 0;; Random.int_in_range ~min:0 ~max:5;; ...)

  Based on the rand nums above, the response should be:
  # permutation ["a"; "b"; "c"; "d"; "e"; "f"];;
  - : string list = ["a"; "f"; "e"; "b"; "c"; "d"]

  From the ocaml website below:
  # permutation ["a"; "b"; "c"; "d"; "e"; "f"];;
  - : string list = ["c"; "d"; "f"; "e"; "b"; "a"]
*)

let permutation (xs: 'a list): 'a list =
  let rec get_loop (i: int) (acc: 'a list) (zs: 'a list): 'a option * 'a list =
    match i, zs with
    | _, [] ->
       None, List.rev acc

    | 0, z :: rest ->
       let remaining: 'a list = (List.append (List.rev acc) rest) in
       Some z, remaining

    | _, z :: rest ->
       get_loop (i - 1) (z :: acc) rest
  in

  let get_elem_and_rest (pos: int) (ys: 'a list): 'a * 'a list =
    let result = get_loop pos [] ys in
    match result with
    | None, _ -> failwith "Position is out of bounds from the list."
    | Some v, rest -> v, rest
  in

  let get_rnd_elem_and_rest (ys: 'a list): 'a * 'a list =
    match ys with
    | [] -> failwith "Empty list. Cant get any random element from it."

    (* Optimization for 1 element list. length 1 wont have random position *)
    | y :: [] -> y, []

    | _ ->
       let min = 0 in
       let max = (List.length ys) - 1 in
       let pos = Random.int_in_range ~min ~max in
       get_elem_and_rest pos ys
  in

  let rec main_loop (ys: 'a list): 'a list =
    match ys with
    | [] -> []
    | _ -> let elem, remaining = get_rnd_elem_and_rest ys in
           elem :: main_loop remaining
  in

  (* Toggle between 0 seed and true random with self_init *)
  Random.init 0;
  (* Random.self_init (); *)
  main_loop xs
;;

let () =
  let result = permutation ["a"; "b"; "c"; "d"; "e"; "f"] in
  let expected = ["a"; "f"; "e"; "b"; "c"; "d"] in
  if result <> expected then
    failwith @@ err_msg ^ "`permutation` Case 1"
;;

(*
  TODO:

  Generate the Combinations of K Distinct Objects Chosen From the N Elements of a List
  Intermediate

  Generate the combinations of K distinct objects chosen from the N elements of a list.

  In how many ways can a committee of 3 be chosen from a group of 12 people? We
  all know that there are C(12,3) = 220 possibilities (C(N,K) denotes the
  well-known binomial coefficients). For pure mathematicians, this result may be
  great. But we want to really generate all the possibilities in a list.

  # extract 2 ["a"; "b"; "c"; "d"];;
  - : string list list =
  [["a"; "b"]; ["a"; "c"]; ["a"; "d"]; ["b"; "c"]; ["b"; "d"]; ["c"; "d"]]
*)

(* Extract with a fixed length of 2 *)
let extract2 (xs: 'a list): 'a list list =

  let rec loop (curr: 'a) (ys: 'a list) (zs: 'a list): 'a list list =
    match ys, zs with
    | [], [] -> []

    | [], z :: tail ->
        loop z tail tail

    | y :: tail, _ ->
        [curr; y] :: loop curr tail zs
  in

  let curr = List.hd xs in
  let tail = List.tl xs in
  loop curr tail tail
;;

(*
  TODO:
  Group the Elements of a Set Into Disjoint Subsets
  Intermediate

  Group the elements of a set into disjoint subsets

  In how many ways can a group of 9 people work in 3 disjoint subgroups of 2, 3
  and 4 persons? Write a function that generates all the possibilities and returns
  them in a list.

  Generalize the above function in a way that we can specify a list of group sizes
  and the function will return a list of groups.

  # group ["a"; "b"; "c"; "d"] [2; 1];;
  - : string list list list =
  [[["a"; "b"]; ["c"]]; [["a"; "c"]; ["b"]]; [["b"; "c"]; ["a"]];
   [["a"; "b"]; ["d"]]; [["a"; "c"]; ["d"]]; [["b"; "c"]; ["d"]];
   [["a"; "d"]; ["b"]]; [["b"; "d"]; ["a"]]; [["a"; "d"]; ["c"]];
   [["b"; "d"]; ["c"]]; [["c"; "d"]; ["a"]]; [["c"; "d"]; ["b"]]]
*)

(*
  TODO:

  Sorting a List of Lists According to Length of Sublists
  Intermediate

  Sorting a list of lists according to length of sublists.

  We suppose that a list contains elements that are lists themselves. The objective
  is to sort the elements of this list according to their length. E.g. short lists
  first, longer lists later, or vice versa.

  Again, we suppose that a list contains elements that are lists themselves. But
  this time the objective is to sort the elements of this list according to their
  length frequency; i.e., in the default, where sorting is done ascendingly, lists
  with rare lengths are placed first, others with a more frequent length come later.

  # length_sort [["a"; "b"; "c"]; ["d"; "e"]; ["f"; "g"; "h"]; ["d"; "e"];
                 ["i"; "j"; "k"; "l"]; ["m"; "n"]; ["o"]];;
  - : string list list =
  [["o"]; ["d"; "e"]; ["d"; "e"]; ["m"; "n"]; ["a"; "b"; "c"]; ["f"; "g"; "h"];
   ["i"; "j"; "k"; "l"]]

  # frequency_sort [["a"; "b"; "c"]; ["d"; "e"]; ["f"; "g"; "h"]; ["d"; "e"];
                    ["i"; "j"; "k"; "l"]; ["m"; "n"]; ["o"]];;
  - : string list list =
  [["i"; "j"; "k"; "l"]; ["o"]; ["a"; "b"; "c"]; ["f"; "g"; "h"]; ["d"; "e"];
   ["d"; "e"]; ["m"; "n"]]
*)
