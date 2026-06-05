#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	
	int result;
	char prompt[60];
	char host[60]; 
	char name[60];

	FILE *canal = popen("whoami", "r");
	fgets(name, sizeof(name), canal);
 	pclose(canal);
	name[strcspn(name, "\n")] = 0;

	canal = popen("echo $HOST", "r");
	fgets(host, sizeof(host), canal);
	pclose(canal);
	host[strcspn(host, "\n")] = 0;

	while (1) {
		printf("%s@%s >", name, host);
		fgets(prompt, sizeof(prompt), stdin);

		prompt[strcspn(prompt, "\n")] = 0;
		if (strcmp(prompt, "exit") == 0) {
			break;
		}
		else {
result = system(prompt);
		}
		if (result == -1) {
			printf("error; try to restart the program");
		}
	}
	return 0; 
}
