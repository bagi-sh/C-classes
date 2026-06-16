#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

int main() {

  char name [LOGIN_NAME_MAX];
	char host [HOST_NAME_MAX];

	getlogin_r(name, sizeof(name));
	gethostname(host, sizeof(host));

  char *prompt;
  prompt = (char *) malloc(dsize);
  int dsize = 60;
  int result;
  char *token;
  char *arg[60];
  char *pfinal;

	while (1) {

    int i = 0;

	  printf("%s@%s:\n", name, host); 

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
    else if (strcmp(arg[0], "cd")) 
      exec_cd(char *arg);

    else if (strcmp(arg[0], "pwd"))
      exec_pwd(char *arg);

    else if (strcmp(arg[0], "ls"))
        exec_ls(char *arg);

    else if (strcmp(arg[0], "cat"))
        exec_cat(char *arg);

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
