(*
  guess-the-number-game.ml
  Pedro Frohmut 2026 Copyrights

  You can start the game with (if from the same folder)
  Usage: ocaml guess-the-number-game.ml

  Guess the number game is a cli game where the user enters a number between 1
  and 100 and tries to guess what is the random generated number in the least
  amount of tries.

  The game validates the input. If valid the game checks if the value is lower,
  bigger or entered the correct answer.

  The game counts the user tries and show a score at the end based on the number
  of tries the user did.
 *)

(**
   Gets an integer random number between first and last.
   Obs: Don't forget to init the seed before calling it.

   {b Parameters:}
   [first]: int - the smaller integer number of the interval to be used
   [last]: int - the bigger integer number of the interval to be used

   {b Returns:}
   : int - The random number between first and last both inclusive
 *)
let get_rand_num (first: int) (last: int): int =
  if first < 0 then
    failwith "The first value must be a positive integer"
  else if last < 0 then
    failwith "The last value must be a positive integer"
  else if not (last > first) then
    failwith "Last must be bigger than first to be valid"
  else
    let rand_limit = (last - first + 1) in
    (Random.int rand_limit) + first

(**
   Calculate the score and Show the game over messages.

   {b Parameters:}
   [tries]: int - Number of times the player tried to guess the random number
 *)
let game_over (tries: int): unit =
  print_endline "You guessed. Congratulations, you won!!";
  Printf.printf "You used %d tries to guess the number.\n" tries;

  let score = 100 - (tries * 10) in
  Printf.printf "You scored %d points.\n" score;

  match score with
  | x when x >= 100 -> print_endline "What is happening? First try. Holy Cow!!!"
  | x when x > 80 -> print_endline "Great!! That's is some game skills right there."
  | x when x > 60 -> print_endline "Good! Not a chad but getting there."
  | x when x > 40 -> print_endline "Could be better but you still won."
  | x when x > 0 -> print_endline "Broh is just guessing at this point."
  | _ -> print_endline "Negative score. Brother uuulll."

(**
   Try to remove the double semicolon at the end if the user is in the ocaml REPL
   or does nothing if there is no suffix sicolons.

   {b Parameters:}
   [input]: string - The string to maybe clean up.

   {b Returns:}
   : string - Either the cleaned up string or the unchanged input.
 *)
let maybe_clean_repl_suffix (input: string): string =
  if not (String.ends_with ~suffix:";;" input) then
    input
  else
    let suffix_len = 2 in
    let input_len = (String.length input - suffix_len) in
    String.sub input 0 input_len

(**
   the game loop the validate user input then check if the guess is correct or not
   then execute game over operations when user guess the number correctly.

   {b Parameters:}
   [rand_num]: int - The number the user is trying to guess
   [first]: int - The minimal valid value for the input
   [last]: int - The maximum valid value for the input
   [tries]: int - The counter that is incremented every time the user make a valid
   but incorrect input
 *)
let rec game_loop (rand_num: int) (first: int) (last: int) (tries: int): unit =
  print_endline "Enter a number between 1 and 100";

  let str_input = read_line() |> maybe_clean_repl_suffix in

  match int_of_string str_input with

  | exception Failure _ ->
     print_endline "Failed to parse the input to an integer number.";
     game_loop rand_num first last tries

  | input when input < first || input > last ->
    Printf.printf "The number should be between %d and %d.\n" first last;
    game_loop rand_num first last tries

  | input when input < rand_num ->
    print_endline "Too low. Try a higher number.";
    game_loop rand_num first last (tries + 1)

  | input when input > rand_num ->
    print_endline "Too high. Try a lower number.";
    game_loop rand_num first last (tries + 1)

  | _ ->
     game_over tries

(**
   Entry point for the game. Inits the random seed, generate a number and says the
   welcome message
 *)
let main (): unit =
  Random.self_init (); (* Uses system to init with a random seed *)

  print_endline "Hello.";
  print_endline "Welcome to the Guess The Number Game!";

  let first = 1 in
  let last = 100 in
  let rand_num = get_rand_num first last in

  print_endline "Now. Try to guess what the number is";
  let tries = 0 in
  game_loop rand_num first last tries

(* Runs the code if not in the REPL. *)
let () =
  if not !Sys.interactive then main () else ()
