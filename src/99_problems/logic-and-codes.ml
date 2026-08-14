(*
  Truth Tables for Logical Expressions (2 Variables)
  Intermediate

  Let us define a small "language" for boolean expressions containing variables:

  # type bool_expr =
    | Var of string
    | Not of bool_expr
    | And of bool_expr * bool_expr
    | Or of bool_expr * bool_expr;;

  type bool_expr =
      Var of string
    | Not of bool_expr
    | And of bool_expr * bool_expr
    | Or of bool_expr * bool_expr

  A logical expression in two variables can then be written in prefix notation.
  For example, (a ∨ b) ∧ (a ∧ b) is written:

  # And (Or (Var "a", Var "b"), And (Var "a", Var "b"));;
  - : bool_expr = And (Or (Var "a", Var "b"), And (Var "a", Var "b"))

  Define a function, table2 which returns the truth table of a given logical expression
  in two variables (specified as arguments). The return value must be a list of triples
  containing (value_of_a, value_of_b, value_of_expr).

  # table2 "a" "b" (And (Var "a", Or (Var "a", Var "b")));;
  - : (bool * bool * bool) list =
  [(true, true, true); (true, false, true); (false, true, false); (false, false, false)]
*)

type bool_expr =
    | Var of string
    | Not of bool_expr
    | And of bool_expr * bool_expr
    | Or of bool_expr * bool_expr
;;

let table2: string -> string -> bool_expr -> (bool * bool * bool) list = fun a b exp ->

  let rec apply elem_a elem_b exp =
    let (a, x) = elem_a in
    let (b, y) = elem_b in
    match exp with
    | Var v when v = a -> x

    | Var _ -> y

    | Not (e) ->
       not (apply elem_a elem_b e)

    | And (left_e, right_e) ->
       apply elem_a elem_b left_e && apply elem_a elem_b right_e

    | Or (left_e, right_e) ->
       apply elem_a elem_b left_e || apply elem_a elem_b right_e
  in

  let r1 = true, true, apply (a, true) (b, true) exp in
  let r2 = true, false, apply (a, true) (b, false) exp in
  let r3 = false, true, apply (a, false) (b, true) exp in
  let r4 = false, false, apply (a, false) (b, false) exp in

  [r1; r2; r3; r4]
;;

let () =
  let res = table2 "a" "b" (And (Var "a", Or (Var "a", Var "b"))) in
  let exp = [(true, true, true); (true, false, true); (false, true, false); (false, false, false)] in
  if res <> exp then
    failwith @@ err_msg ^ "`table2` Case 1"
;;

(*
  TODO:

  Truth Tables for Logical Expressions
  Intermediate

  Generalize the previous problem in such a way that the logical expression may
  contain any number of logical variables. Define table in a way that table
  variables expr returns the truth table for the expression expr, which contains
  the logical variables enumerated in variables.

  # table ["a"; "b"] (And (Var "a", Or (Var "a", Var "b")));;
  - : ((string * bool) list * bool) list =
  [([("a", true); ("b", true)], true);
   ([("a", true); ("b", false)], true);
   ([("a", false); ("b", true)], false);
   ([("a", false); ("b", false)], false)]
*)

(*
  Gray Code
  Intermediate

  An n-bit Gray code is a sequence of n-bit strings constructed according to
  certain rules. For example,

  n = 1: C(1) = ['0', '1'].
  n = 2: C(2) = ['00', '01', '11', '10'].
  n = 3: C(3) = ['000', '001', '011', '010', '110', '111', '101', '100'].

  Find out the construction rules and write a function with the following
  specification: gray n returns the n-bit Gray code.

  # gray 1;;
  - : string list = ["0"; "1"]
  # gray 2;;
  - : string list = ["00"; "01"; "11"; "10"]
  # gray 3;;
  - : string list = ["000"; "001"; "011"; "010"; "110"; "111"; "101"; "100"]
 *)

(*
  Huffman Code
  Advanced

  First of all, consult a good book on discrete mathematics or algorithms for a
  detailed description of Huffman codes (you can start with the Wikipedia page)!

  We consider a set of symbols with their frequencies. For example, if the
  alphabet is "a",..., "f" (represented as the positions 0,...5) and respective
  frequencies are 45, 13, 12, 16, 9, 5:

  # let fs = [("a", 45); ("b", 13); ("c", 12); ("d", 16);
              ("e", 9); ("f", 5)];;
  val fs : (string * int) list =
  [("a", 45); ("b", 13); ("c", 12); ("d", 16); ("e", 9); ("f", 5)]

  Our objective is to construct the Huffman code word for all symbols s. In our
  example, the result could be hs = [("a", "0"); ("b", "101"); ("c", "100");
  ("d", "111"); ("e", "1101"); ("f", "1100")] (or hs = [("a", "1");...]). The
  task shall be performed by the function huffman defined as follows: huffman(fs)
  returns the Huffman code table for the frequency table fs

  # huffman fs;;
  - : (string * string) list =
  [("a", "0"); ("c", "100"); ("b", "101"); ("f", "1100"); ("e", "1101"); ("d", "111")]
*)
