#include <stdio.h> 
#include <inttypes.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define FILE_PATH "./myLog.txt"

int main(void)
{
	int fd = open( FILE_PATH, O_RDONLY);
	char ch;
	int IsDone = 1;
	int byte_len;
	while(IsDone){
		
		byte_len = read( fd, &ch, 1);
		printf("%c", ch);
		if(byte_len <= 0){
			printf("find the end of file!");
			break;
		}
	
	}
	
	close(fd);
	
	
	return 0;
}
