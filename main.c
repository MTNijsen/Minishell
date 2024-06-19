#include "executor.h"
#include <sys/stat.h>


int main(int argc, char *argv[], char *envp[])
{
	char *output1;
	char *output2;

	printf("%d\n", strncmp(NULL, argv[0], 0));
}