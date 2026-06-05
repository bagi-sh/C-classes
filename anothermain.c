#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	
	char host[60]; 
	char name[60];

#ifdef _WIN32
#include <windows.h>
	DWORD size = sizeof(name);
	GetUserNameA(name, size);
#else 
	#include <unistd.h>
	getlogin_r(name, sizeof(name));
#endif

#ifdef _WIN32
    DWORD tamanho_host = sizeof(host);
    GetComputerNameA(host, &tamanho_host);
#else
    gethostname(host, sizeof(host));
#endif

	int result;
	char prompt[60];

	while (1) {
		printf("%s@%s >\n", name, host);
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
		else if (result == 127) {
			printf("error; command doesn't exist");
		}
	}
	return 0; 
}
