Create our own UNIX command line interpreter that mimics a basic shell. This is a group project. Our shell should:

- Display prompt each time a command has been executed
- Handle the EOF condition
- Execute command lines with arguments
- Be able to implement select builtins namely the "exit" and "env" builtins
- Handle the path environmental variable

Note that the shell should work both in the interactive and non-interactive mode. Please be aware of memory leaks as well; run valgrind every few times to check. 
