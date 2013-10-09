#include <stdio.h> 
#include <inttypes.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define FILE_PATH "./myLog.txt"
#define BUFFER_SIZE 100
int main(void)
{
	int fd = open( FILE_PATH, O_RDONLY);
	char buff[BUFFER_SIZE];
	int IsDone = 1;
	int byte_len;
	/*error handling*/
	if( fd == -1){
		printf("file not found\n");
		return 0;
	}
	else{
		printf("found file, start reading...");
	
	}
	int counter = 0;
	/*reading loop*/
	while(IsDone){
		byte_len = read( fd, buff, BUFFER_SIZE);
		if(byte_len <= 0){
			printf("find the end of file!");
			break;
		}
		else{
			printf("%s", buff);
		}
		
	}
	


	close(fd);
	
	
	return 0;
}
