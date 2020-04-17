# Shell Replica 

*Summary of project*

Hello, this is the simple shell project created by Andersen Castañeda and Santiago Arboleda. This basic shell allows executing the main features that any shell has in your Unix terminal.

## Installation

1. To begin, you need to clone this repository on your local machine with one of those two commands.

- $ git clone https://github.com/blazeker/simple_shell.git

- Check if you find all the scripts

```bash
- _exitcall.c
- _path.c
- aux_check.c
- copy_string.c
- directory_functions.c
- malloc_free.c
- print_errors.c
- print_prompt.c
- shell.h
- shell.c
- split_aux.c
- str2_functions.c
- str_functions.c
```

2. Compile it with the command:

- $ make all

3. Execute the shell program with the command:

- $ ./hsh

Commands of the shell!

As any shell, this follows the same syntax to execute commands that is:

```bin
$ <command> <flags> <argument 1> <argument 2> ...
```

And have a non-interactive mode that is:

```bin
$ <command> <command> <flags> <argument 1> <argument 2> ... | ./hsh
```

## Usage

Running the shell and prompting command on an interactive way:

- After compiling, executes the shell programm
- Run commands like ls, echo, pwd, whoami, ect.

### _Example_

```bin
$ /bin/ls
```
```bin
$ ls -l -a -v
```
```bin
$ echo "message that you want to replicate"
```

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.

## License
[MIT](https://choosealicense.com/licenses/mit/)

## Authors
- Andersen Castañeda [@AndersenCastaneda](https://www.github.com/AndersenCastaneda)
- Santiago Arboleda  [@Blazeker](https://www.github.com/Blazeker)