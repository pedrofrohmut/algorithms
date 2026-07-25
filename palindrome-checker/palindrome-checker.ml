(*
  palindrome-checker.ml
  Pedro Frohmut 2026 Copyrights

  Checks if a string is a palindrome.
  A palindrome is a word that can be read from left to right and right to left.
 *)

let rev_str (src: string): string =
    let rec loop (acc: string) (src: string): string =
      let len = String.length src in
      if len = 0 then
        acc

      else
        let ch = String.get src 0 |> String.make 1 in
        if len < 2 then
          loop (ch ^ acc) ""

        else
          let rest = String.sub src 1 (len - 1) in
          loop (ch ^ acc) rest
    in
    match String.length src with
    | 0 -> ""
    | 1 -> src
    | _ -> loop "" src

(* Checks if the string source is the same of its reverse.
   More expensive but works fine. *)
let is_palindrome_str (src: string): bool =
  src = rev_str src

(* Checks char by char if the current char matches the correspondent char in the
   opposite position. Exp src.[2] = src[len - 2 - 1].
   -> More efficient no extra operations. Only loops half times the length of the
   string. *)
let is_palindrome (src: string): bool =
  let rec loop (src: string) (i: int) (j: int): bool =
    if i > j then
      true

    else if src.[i] != src.[j] then
      false

    else
      loop src (i + 1) (j - 1)
  in

  let len = String.length src in
  match len with
  | 0 -> true
  | 1 -> true
  | _ -> loop src 0 (len - 1)

let test (label: string) (is_palindrome_fun: string -> bool) (src: string) (expected: bool): unit =
  let result = is_palindrome_fun src in
  if result != expected then
    Printf.printf "Error -> %s with '%s' expected '%B' but got '%B' instead.\n" label src expected result

let main (): unit =
  test "is_palindrome_str" is_palindrome_str "foobar" false;
  test "is_palindrome_str" is_palindrome_str "racecar" true;
  test "is_palindrome_str" is_palindrome_str "carac" true;
  test "is_palindrome_str" is_palindrome_str "ababa" true;
  test "is_palindrome_str" is_palindrome_str "hello" false;

  test "is_palindrome" is_palindrome "foobar" false;
  test "is_palindrome" is_palindrome "racecar" true;
  test "is_palindrome" is_palindrome "carac" true;
  test "is_palindrome" is_palindrome "ababa" true;
  test "is_palindrome" is_palindrome "hello" false

let () = main ()
