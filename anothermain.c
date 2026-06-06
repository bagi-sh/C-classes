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

  char prompt[60];
  int result;

	while (1) {

		printf("%s@%s:\n", name, host); //cria o prompt

		fgets(prompt, sizeof(prompt), stdin); //lê entrada e coloca na variável prompt
		if (strchr(prompt, '\n') == NULL) {
			while (getchar() != '\n' && getchar() != EOF); // limpa o buffer
		}

    char *token
    char *arg[60];
    int i = 0;

    token = strtok(prompt, " ");
    while (token != NULL) {
      arg[i] = token;
      i++;
      strtok(NULL, " ");
    }
    arg[i] = NULL;

		prompt[strcspn(prompt, "\n")] = 0; // remove o carctere de noca linha
		if (strcmp(args[0], "exit") == 0) {
			break;
		}
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
	return 0; 
}
