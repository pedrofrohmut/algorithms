let reverse_string (src: string): string =
  let rec aux (acc: string) (src: string): string =
    if src = "" then
      acc
    else
      let ch = String.get src 0 in
      let ch = String.make 1 ch in
      let len = String.length src in
      let rest = if len > 1 then String.sub src 1 (len - 1) else "" in
      aux (ch ^ acc) rest
  in
  aux "" src

let test_rev (rev_fun: string -> string) (src: string) (expected: string): unit =
  let reversed = rev_fun src in
  if not (reversed = expected) then
    Printf.printf "[Error] Expected reverse of '%s' to be '%s' but got '%s' instead\n" src reversed expected
  else
    Printf.printf "[Success] Passing for '%s'\n" src

let main (): unit =
  test_rev reverse_string "foobar" "raboof"

let () = main ()
