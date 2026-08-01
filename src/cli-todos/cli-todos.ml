#!/usr/bin/env ocaml

let print_all_args (): unit =
  for i = 0 to Array.length Sys.argv - 1 do
    Printf.printf "[%i] %s\n" i Sys.argv.(i)
  done

let show_help (): unit =
  print_endline {|Usage: cli-todos [command] [args]

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
  print_endline {|cli-todos 1.0
Pedro Frohmut 2026 Copyrights.
License MIT.|}

let show_invalid_message (): unit =
  print_endline {|Invalid option.
 The valid options are: list, add, remove, etc.
 You can see at help with `cli-todos --help`.|}

let list_todos (file_name: string): unit =
  if not @@ Sys.file_exists file_name then
    print_endline "No todos to list at the moment."
  else
    failwith "Not implemented: Read and list the todos with line numbers"

let array_has_next (arr: 'a array) (position: int): bool =
  (position + 1) < Array.length arr

let add_todo (file_name: string) (args: string array) (position: int): unit =
  let err_msg = "There is no text after the command to be used as the todo text." in
  let has_next_arg () = array_has_next args position in
  let is_next_arg_flag () = String.starts_with ~prefix:"-" args.(position + 1) in

  if not (has_next_arg ()) then
    print_endline err_msg
  else if is_next_arg_flag () then
    print_endline err_msg
  else
    let todo_text = args.(position + 1) in

    (* append the text to the file *)
    let out_channel = open_out_gen [Open_creat; Open_append] 0o644 file_name in
    Printf.fprintf out_channel "%s\n" todo_text;
    close_out out_channel

(* TODO: Keep reading the arguments after all the cases.
   Maybe read all the args to a datastructure and the use struct_has "-h" | "--help" *)
let process_args (args: string array) (file_name: string): unit =
  let loop i args =
    let curr = args.(i) in
    match curr with
    | "-h" | "--help" -> show_help ()
    | "--interactive-help" -> show_interactive_help ()
    | "-v" | "--version" -> show_version ()
    | "list" -> list_todos file_name
    | "add" -> add_todo file_name args i
    | "remove" -> failwith "Not implemented"
    | _ -> show_invalid_message ()
  in
  loop 1 args

let main (): unit =
  if !Sys.interactive then
    failwith "This tool is not compatible with the repl"
  else
    let args = Sys.argv in
    if Array.length args = 1 then
      show_help ()
    else
      let file_name = "cli-todos-db.txt" in
      process_args args file_name

let () =
  if !Sys.interactive then () else main ()
