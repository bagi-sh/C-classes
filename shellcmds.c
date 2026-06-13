#include "builtins.h" 
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void exec_cd(char *arg[]) {
    if (arg[1] == NULL) {
        chdir(getenv("HOME"));
    }
    if (strchr('~', arg)) 
}