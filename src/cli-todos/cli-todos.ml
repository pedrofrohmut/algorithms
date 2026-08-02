#!/usr/bin/env ocaml

let print_all_args (): unit =
  for i = 0 to Array.length Sys.argv - 1 do
    Printf.printf "[%i] %s\n" i Sys.argv.(i)
  done

let print_separator (): unit =
  Printf.printf "\n----------------------------------------\n\n"

let show_help (): unit =
  print_endline {|Usage: cli-todos [flag | command [args]]...

 List, Add, Remove todos from a file using this cli tool. You can add todos to the
current todos file with `cli-todos add "buy milk"`. You can remove todos after
they are done from file from file with `cli-todos remove 2`, passing the line
number. You can check your todos and get the line number with `cli-todos list`.

List of options/flags:
 -h/--help				  Show this help.
 -v/--version			  Show version information.
 list					  List the Todos in the file preceded by the line number.
 remove [line-number]	  Remove a todo passing the line number. You can discover
the line number with the command list.
 add [todo-text]		  Append a new todo to the file.
|}

let show_interactive_help (): unit =
  print_endline {|Usage: in the REPL enter `main ~user_args:([| "arg1"; "arg2"; ...; "argN" |]) ();;`
Obs: arg0 is not needed. It will be provided by the tool.|}

let show_version (): unit =
  print_endline {|Version: cli-todos 1.0
Pedro Frohmut 2026 Copyrights.
License MIT.|}

let show_invalid_message (): unit =
  print_endline {|Invalid option.
 The valid options are: list, add, remove, etc.
 You can see at help with `cli-todos --help`.|}

let get_in_channel (file_name: string): in_channel =
  open_in_gen [Open_rdonly; Open_text] 0o644 file_name

let get_out_channel_append (file_name: string): out_channel =
  open_out_gen [Open_creat; Open_append] 0o644 file_name

let list_todos (file_name: string): unit =
  if not @@ Sys.file_exists file_name then
    print_endline "No todos to list at the moment."
  else
    let in_channel = get_in_channel file_name in
    let lines = In_channel.input_lines in_channel in

    if List.length lines == 0 then
      print_endline "No todos at the moment."
    else
      List.iteri (fun index line -> Printf.printf "%d - %s\n" (index + 1) line) lines;

    close_in in_channel

let array_has_next (arr: 'a array) (position: int): bool =
  (position + 1) < Array.length arr

let is_flag (str: string): bool =
  if not (String.starts_with ~prefix:"-" str) then
    false
  else
    try
      let _ = int_of_string str in
      false (* a negative number also starts with a dash *)
    with _ ->
      true

let add_todo (file_name: string) (args: string array) (position: int): unit =
  let err_msg = "There is no text after the command to be used as the todo text." in
  let has_next_arg () = array_has_next args position in
  let is_next_arg_flag () = is_flag args.(position + 1) in
  let is_empty_text () = String.is_empty @@ String.trim args.(position + 1) in

  (* Lazy conditions to avoid runtime errors *)
  if not (has_next_arg ()) then
    print_endline err_msg
  else if is_next_arg_flag () then
    print_endline err_msg
  else if is_empty_text () then
    print_endline "Todo text cannot be empty or blank"
  else
    let todo_text = args.(position + 1) in

    (* append the text to the file *)
    let out_channel = get_out_channel_append file_name in
    Printf.fprintf out_channel "%s\n" (String.trim todo_text);
    close_out out_channel;

    print_endline "Todo added.";
    list_todos file_name

let remove_from_list (position: int) (xs: 'a list): 'a list =
  let before = List.take (position - 1) xs in
  let after = List.drop position xs in
  List.append before after

let remove_todo (file_name: string) (args: string array) (position: int): unit =
  let err_msg =  "There is no line number after the command to be a reference to remove to todo." in
  let err_msg2 = "Line number needs to be a positive integer bigger than zero." in
  let has_next_arg () = array_has_next args position in
  let is_next_arg_flag () = is_flag args.(position + 1) in

  if not (has_next_arg ()) then
    print_endline err_msg
  else if is_next_arg_flag () then
    print_endline err_msg
  else
    match int_of_string args.(position + 1) with
    | exception Failure _ ->
       print_endline err_msg2
    | n when n < 1 ->
       print_endline err_msg2
    | n ->
       let in_channel = get_in_channel file_name in
       let lines = In_channel.input_lines in_channel in
       if n > List.length lines then
         begin
           print_endline "Line to remove is too big. Check out the correct line number";
           list_todos file_name
         end
       else
         let new_lines = remove_from_list n lines in
         let out_channel = open_out file_name in
         List.iter (fun new_line -> Printf.fprintf out_channel "%s\n" new_line) new_lines;
         close_out out_channel;
         list_todos file_name

let process_args (args: string array) (file_name: string): unit =
  let rec loop i args =
    if i >= Array.length args then
      ()
    else
      (* 1 for the command + 1 for each extra argument the command takes *)
      let increment = match args.(i) with
        | "-h" | "--help" -> show_help (); 1
        | "--interactive-help" -> show_interactive_help (); 1
        | "-v" | "--version" -> show_version (); 1
        | "list" -> list_todos file_name; 1
        | "add" -> add_todo file_name args i; 2
        | "remove" -> remove_todo file_name args i; 2
        | _ -> show_invalid_message (); 1
      in
      let next_i = i + increment in

      if next_i < Array.length args then print_separator ();

      loop next_i args
  in
  loop 1 args

let main (): unit =
  if !Sys.interactive then
    print_endline "This tool is not compatible with the repl"
  else
    let args = Sys.argv in
    if Array.length args = 1 then
      show_help ()
    else
      let file_name = "cli-todos-db.txt" in
      process_args args file_name

let () =
  if !Sys.interactive then () else main ()
