The assignment in question is [here](http://www.cs.ucsb.edu/~chris/teaching/cs170/projects/proj1.html). So far, I have implemented a very simple shell, that supports running programs with arguments. There is no support for operators `&`, `|`, `<`, `>`. It also doesn't support the `-n` option just yet. Otherwise, it works! :-)

## Sample session

    shell: echo yes
    yes
    shell: ls
    Makefile  README.md  simple_shell  simple_shell.c
    shell: <Ctrl-D>
