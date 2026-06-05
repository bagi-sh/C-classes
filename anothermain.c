#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifdef _WIN32
	#include <windows.h>
	#include <lmcons.h>
	char name[UNLEN + 1];
	DWORD size = sizeof(name);
	GetUserNameA(name, size);

	char host[MAX_COMPUTERNAME_LENGTH + 1];
	DWORD tamanho_host = sizeof(host);
	GetComputerNameA(host, &tamanho_host);
#else 
	#include <unistd.h>
	#include <limits.h>
	char name [LOGIN_NAME_MAX];
	char host [HOST_NAME_MAX];

	getlogin_r(name, sizeof(name));
	gethostname(host, sizeof(host));
#endif

int main() {
	

	int result;
	char prompt[60];

	while (1) {
		printf("%s@%s >\n", name, host);
		fgets(prompt, sizeof(prompt), stdin);
		
		if (strchr(prompt, '\n') == NULL) {
			while (getchar() != '\n' && getchar() != EOF);
		}
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
		else if (result == 127) {
			printf("error; command doesn't exist");
		}
	}
	return 0; 
}
