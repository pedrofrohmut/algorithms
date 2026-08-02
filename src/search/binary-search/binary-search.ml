(*
  binary-search.ml
  Pedro Frohmut 2026 Copyrights

    Searches for an element in a sorted array looking for the middle element and
  checking if it is bigger or smaller than the element searched. If not found,
  gets the right side if the element is smaller than middle element an left side
  otherwise.
    With the slice, you look at the middle element again and split it again if the
  element is not found. And keeps spliting and looking at the middle element until
  the element is found or the array is has lenght = 1.
 *)

#use "../../utils/utils.ml";;

let get_middle (first: int) (last: int): int =
  if first > last then
    failwith "First cannot be bigger then last"
  else if first = last then
    first
  else
    let diff = last - first in
    let result = (diff / 2) + first in
    (* Doing + 1 for odd numbers to avoid converting to floats and then Math.ceil in the result *)
    if Utils.is_odd diff then result + 1 else result

let binary_search (elem: 'a) (xs: 'a array): int =
  let rec loop elem xs low high =
    if low > high then failwith "Left position can never be bigger than right position"
    else
      (* Base cases *)
      if xs.(low) = elem then low
      else if xs.(high) = elem then high
      else if (high - low) <= 1 then -1 (* Not found *)

      else
        let mid_pos = get_middle low high in
        let mid_elem = xs.(mid_pos) in
        if mid_elem > elem
        then loop elem xs low mid_pos (* Take the left slice + mid_elem *)
        else loop elem xs mid_pos high (* Take the right slice + mid_elem *)
  in
  let len = Array.length xs in
  loop elem xs 0 (len - 1)

let main (): unit =
  Random.self_init (); (* Uses system to init with a random seed *)

  let rnd_start = 1 in
  let rnd_end = 100 in
  let rnd_array = Utils.gen_rnd_array 50 rnd_start rnd_end in
  Array.sort (fun a b -> a - b) rnd_array;
  let rnd_elem = Utils.gen_rnd_int rnd_start rnd_end in

  let res_pos = binary_search rnd_elem rnd_array in

  let str_arr = Utils.string_of_array rnd_array in

  match res_pos with
  | -1 -> Printf.printf "Element %d not found in the array [%s]\n" rnd_elem str_arr
  |  _ -> Printf.printf "Element %d found at position %d in the array [%s]\n" rnd_elem res_pos str_arr

let () =
  if !Sys.interactive then main () else ()
