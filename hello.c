#include <stdio.h>
#include <inttypes.h>

int main(void)
{
	char input[80];
	FILE * myLog;
	char ch;
	puts("You has called a semi-host. enter y to write a log");
	puts("reading file from workspace....\n");
	myLog = fopen("myLog", "a");//append file
	puts("Please write some log!\n");
	gets(input);
	fprintf(myLog ,"%s\n", input);
	fclose(myLog);

	return 0;
}
