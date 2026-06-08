#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

int main() {
// extraindo usuario e host do sistema
  char name [LOGIN_NAME_MAX];
	char host [HOST_NAME_MAX];

	getlogin_r(name, sizeof(name));
	gethostname(host, sizeof(host));

  char *prompt;
  prompt = (char *) malloc(60 * sizeof(char));
  int dsize = 60;
  int result;
  char *token;
  char *arg[60];
  int i = 0;


	while (1) {

		printf("%s@%s:\n", name, host); //cria o prompt

		fgets(prompt, dsize, stdin); //lê entrada e coloca na variável prompt

    while (strchr(prompt, '\n') == NULL && dsize < 4096) {
      dsize = dsize + 60;
      prompt = (char *) realloc(prompt, dsize);
      pfinal = prompt + strlen(prompt);
      fgets(pfinal, 61, stdin);
    }

    if (strchr(prompt, '\n') == NULL) {
      printf("Error; your prompt is bigger than 4096 bytes. \n");
      int c
      while((c = getchar()) != '\n' && c != EOF);
        contine;
    }

  prompt[strcspn(prompt, "\n")] = 0; // remove o carctere de nova linha

    token = strtok(prompt, " ");
    while (token != NULL && i < 59) {
      arg[i] = token;
      i++;
      token = strtok(NULL, " ");
    }
    arg[i] = NULL;

		if (strcmp(args[0], "exit") == 0) {
			break;
		}
		else {
			result = system(prompt);
      free(prompt);
		}
		if (result == -1) {
			printf("error; try to restart the program");
		}
		else if (result == 127) {
			printf("error; command doesn't exist");
		}
	}
	return 0; 
}
