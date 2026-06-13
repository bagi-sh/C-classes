#include "builtins.h" 
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

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

void exec_pwd() {
    char wd[4096];
    if (getcwd(wd, 4096) != NULL) { 
        printf("%s\n", wd);
    } else {
        printf("Error: couldn't found your current directory");
    }
}
void exec_ls(arg[1]) {
    
    DIR *list 
    if (arg[1] == NULL) {
        arg[1] = '.';
        *list = opendir(arg[1]);
        if (list == NULL) {
            perror("Error: the directory doesn't exist or you don't have permission to read");
            return;
        }
    } else {
        list = opendir(arg[1]);
        if (list == NULL) {
            perror("Error: the directory doesn't exist or you don't have permission to read");
            return;
        }
    }

    struct dirent *output
    while ((output = readdir(list)) != NULL) {
        printf("%s\n" output->d_name)
    } 
}