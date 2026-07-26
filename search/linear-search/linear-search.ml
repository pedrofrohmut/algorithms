(*
  linear-search.ml
  Pedro Frohmut 2026 Copyrights

  search for a element in a list from start to finish
 *)

(* Searches from position 0 to array length - 1 for an element with step counter + 1 *)
let search (elem: 'a) (xs: 'a array): 'a option =
  let rec loop (i: int) (elem: 'a) (xs: 'a array): 'a option =
    if i = (Array.length xs) then
      None
    else if xs.(i) = elem then
      Some elem
    else
      loop (i + 1) elem xs
  in
  loop 0 elem xs

let gen_rnd_int (rnd_min: int) (rnd_max: int): int =
  (Random.int (rnd_max - rnd_min + 1)) + rnd_min

let gen_rnd_array (length: int) (rnd_min: int) (rnd_max: int): int array =
  Array.init length (fun _ -> gen_rnd_int rnd_min rnd_max)

let main (): unit =
  Random.self_init (); (* Uses system to init with a random seed *)

  let rnd_start = 1 in
  let rnd_end = 100 in
  let rnd_array = gen_rnd_array 50 rnd_start rnd_end in
  let rnd_elem = gen_rnd_int rnd_start rnd_end in
  let search_result = search rnd_elem rnd_array in
  let str_array = rnd_array
                  |> Array.map string_of_int
                  |> Array.to_list
                  |> String.concat ", " in

  match search_result with
  | None -> Printf.printf "Element %d not found in the array [%s]\n" rnd_elem str_array
  | Some x -> Printf.printf "Element %d found in the array [%s]\n" rnd_elem str_array

let () =
  if not !Sys.interactive then main () else ()
