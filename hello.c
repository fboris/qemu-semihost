#include <stdio.h> 
#include <inttypes.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define FILE_PATH "./myLog.txt"
#define BUFFER_SIZE 100
int generate_checksum(char* str)
{
	int len = strlen(str);
	char check_sum;

	check_sum = str[0];
	
	for (int i = 1 ; i< len ; i++){
		check_sum = check_sum^str[i];
	}
	return check_sum;

}
int main(void)
{
	int fd = open( FILE_PATH, O_RDWR);
	char buff[BUFFER_SIZE];
	int byte_len;
	buff[BUFFER_SIZE-1] = '\0';
	/*error handling*/
	if( fd == EOF ){
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
			printf("\n=find the end of file=\n!");
			break;
		}
		else{
			if( byte_len < BUFFER_SIZE ){
				buff[byte_len] = '\0';//keep last one character in string is '0'
			}

			printf("%s", buff);
		}
		
	}
	
	int key;
	char eat;
	int IsDone=1;
	while(IsDone){
		puts("\r\nWould you like to add a record?(Y/N)");
		key = getchar();
		eat = getchar();//prevent gets() get '\n' character 
		if( (key =='y') || (key=='Y') ){
			printf("please enter your message:\n");
			if( gets( buff) != NULL ){
				int checksum = generate_checksum(buff);
				/*pass a single char to a buffer*/
				char temp[2] = {'\0','\0'};
				temp[0] = checksum;
				write( fd, "\r\n", 2);
				write( fd, buff, strlen(buff));	
				write( fd, "#",2);
				write( fd, temp, 2);
				printf("\r\nYour checksum is %x", checksum);

			}
			else{
				printf("\r\nYour typing has some error!");
				IsDone = 1;
			}
			key = 0;
		}
		else if( (key =='n') || (key=='N') ){
			
			printf("End semi-host");
			IsDone = 0;

		}
	}
	close(fd);
	
	
	return 0;
}
