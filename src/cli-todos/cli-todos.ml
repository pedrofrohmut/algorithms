#!/usr/bin/env ocaml

let print_all_args (): unit =
  for i = 0 to Array.length Sys.argv - 1 do
    Printf.printf "[%i] %s\n" i Sys.argv.(i)
  done
;;

let show_help (): unit =
  print_endline @@ {|Usage: cli-todos [command] [args]

List, Add, Remove todos from a file using this cli tool. You can create a new todo
file in the current folder with `cli-todos new`. Then with this file you can add
todos to your list or remove todos after they are already done. You can also just
check the list.

List of options/flags:
 -h/--help				  Show this help.
 -v/--version			  Show version information.
 list					  List the Todos in the file preceded by the line number.
 remove [line-number]	  Remove a todo passing the line number. You can discover
the line number with the command list.
 add [todo-text]		  Append a new todo to the file.
 new					  Create a new todo file in the current folder
|}
;;

let show_version (): unit =
  print_endline @@ {|cli-todos 1.0
Pedro Frohmut 2026 Copyrights.
License MIT.|}
;;

let process_args (args: string array): unit =
  let loop i args =
    let curr = args.(i) in
    match curr with
    | "-h" | "--help" -> show_help ()
    | "-v" | "--version" -> show_version ()
  in
  loop 1 args
;;

let main (): unit =
  let args = Sys.argv in
  if Array.length args = 1 then
    show_help ()
  else
    process_args args
;;

let () =
  if !Sys.interactive then () else main ()
;;
