#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include "shellcmds.h"

int main() {

  char name [LOGIN_NAME_MAX];
	char host [HOST_NAME_MAX];

	getlogin_r(name, sizeof(name));
	gethostname(host, sizeof(host));

  char *prompt;
  int dsize = 60;
  prompt = (char *) malloc(dsize);
  int result;
  char *token;
  char *arg[60];
  char *pfinal;

	while (1) {

    int i = 0;

	  printf("%s@%s: ", name, host); 

		fgets(prompt, dsize, stdin);
    
    while (strchr(prompt, '\n') == NULL && dsize < 4096) {
      dsize = dsize + 60; 
      prompt = (char *) realloc(prompt, dsize); 
      pfinal = prompt + strlen(prompt); 
      // fgets lê apartir do endereço em que prompt acabou + 70 caracteres e o \0
      fgets(pfinal, 65, stdin);
    }

    if (strchr(prompt, '\n') == NULL) {
      printf("Error; your prompt is bigger than 4096 bytes. \n");
      int c;
      while((c = getchar()) != '\n' && c != EOF);
        continue;
    }

  prompt[strcspn(prompt, "\n")] = 0; // serve para limpar o array antes de tokenizar executar

    token = strtok(prompt, " ");
    while (token != NULL && i < 59) {
      arg[i] = token;
      i++;
      token = strtok(NULL, " ");
    }
    arg[i] = NULL; // define o ultimo caractere como \0 pq o execvp vai exigir isso mais tarde

		if (strcmp(arg[0], "exit") == 0) {
			break;
		}
    else if (strcmp(arg[0], "cd") == 0) 
      exec_cd(arg);

    else if (strcmp(arg[0], "pwd") == 0)
      exec_pwd();

    else if (strcmp(arg[0], "ls") == 0)
        exec_ls(arg);

    else if (strcmp(arg[0], "cat") == 0)
        exec_cat(arg);

    else {
			result = system(prompt);
		}
		if (result == -1) {
			printf("error; try to restart the program");
		}
		else if (result == 127) {
			printf("error; command doesn't exist");
		}
	}
  free(prompt);
	return 0; 
}
