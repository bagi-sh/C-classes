#include "builtins.h" 
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void exec_cd(char *arg[]) {
    if (arg[1] == NULL) {
        char *home[1024] = (getenv("HOME"));
        if (home != NULL) chdir(home);
    }
    elseif (arg[1] == '~') {
        char *home[1024] = (getenv("HOME"));
        if (home != NULL) {
            char way[2048];
            strcpy(way, home);
            strcat(way, arg[1] + 1);
            chdir(way);
        }
    }
    else {
        chdir(arg[1]);
    }
}
