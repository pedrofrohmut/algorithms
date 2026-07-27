module Utils = struct

  let hello (name: string): unit =
    Printf.printf "Hello, %s!\n" name

  let gen_rnd_int (rnd_min: int) (rnd_max: int): int =
    (Random.int (rnd_max - rnd_min + 1)) + rnd_min

  let gen_rnd_array (length: int) (rnd_min: int) (rnd_max: int): int array =
    Array.init length (fun _ -> gen_rnd_int rnd_min rnd_max)

  let is_odd (num: int): bool =
    num mod 2 = 1

  let is_even (num: int): bool =
    num mod 2 = 0

  let string_of_array (xs: int array): string =
    xs
    |> Array.map string_of_int
    |> Array.to_list
    |> String.concat ", "

end
