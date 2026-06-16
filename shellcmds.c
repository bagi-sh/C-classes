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
  } else {
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

void exec_ls(char *arg[1]) {
    
  DIR *list;
  if (arg[1] == NULL) {
    arg[1] = ".";
    list = opendir(arg[1]);

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

  struct dirent *output;
  while ((output = readdir(list)) != NULL) {
    printf("%s\n" output->d_name);
    closedir(list);
  } 
}

void exec_cat(char *arg[]) {

if (arg[1] == NULL) {
    printf("cat: Arquivo não especificado\n");
    return;
  }

  FILE *alvo = fopen(arg[1], "r");
  if (alvo == NULL) {
    perror("Error");
    return; 
  }

  char *output;
  int size = 60;
  int position = 0;
  output = (char *) malloc(size);
  int letter;

  while ((letter = fgetc(alvo)) != EOF) {
    if (position >= 4096 -1) {
      printf("\n[cat: Arquivo muito grande, lendo apenas os primeiros 4095 bytes]\n");
      break;
    }
    if (position >= size - 1) {
      size += 60;
      char *temp = (char *) realloc(output, size);
      if (temp == NULL) {
        perror("Error: unexpected memory error");
        free(output);
        closedir(alvo);
        return;
      }
      output = temp; 
    }
    output[position] = (char)c;
    position++;
  }
  output[position] = '\0';
  printf("%s \n", output);
  free(output);
  closedir(alvo);
}
