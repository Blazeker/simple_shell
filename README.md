Summary of project

Hello, this is the simple shell project created by Andersen Castañeda and Santiago Arboleda.
This basic shell allows to execute the main features that any shell have in your unix terminal.

How to run it!

To begin, you need to clone this repository on your local machine with one of those two commands.

$ git clone https://github.com/blazeker/simple_shell.git

or

$ git clone https://github.com/blazeker/simple_shell.git

Then, compile it.

$ make all

And execute the shell.

$ ./hsh

Commands of the shell!

As any shell, this follows the same syntax to execute commands that is:

$ <command> <flags> <argument 1> <argument 2> ...

And have a non-interactive mode that is:

$ <command> <command> <flags> <argument 1> <argument 2> ... | ./hsh

Examples

Running the shell and prompting command on a interactive way:

./hsh

$ /bin/ls

or

$ ls -l -a -1

or

$ echo "message that you want to replicate"

The syntax of non-interactive way is:

$ echo "ls -la1" | ./hsh
