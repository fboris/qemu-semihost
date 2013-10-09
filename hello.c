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
	int byte_len;
	buff[BUFFER_SIZE-1] = '\0';
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
	while(1){
		byte_len = read( fd, buff, BUFFER_SIZE-1);//keep last one character in string is '\0'
		if(byte_len <= 0){
			printf("find the end of file!");
			break;
		}
		else{
			if( byte_len < BUFFER_SIZE ){
				buff[byte_len] = '\0';//keep last one character in string is '0'
			}

			printf("%s", buff);
		}
		
	}
	
	close(fd);
	
	
	return 0;
}
