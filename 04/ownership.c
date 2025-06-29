#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>

//assuming reference time is from an hour ago

int main(){

	//run time inputs
	char file[100];
	printf("Enter file path: ");
	scanf("%s", file);
	char date[80];
	printf("Reference date will be an hour ago. Press 'y' to proceed: ");
	scanf("%s", date);

	printf("Enter permission you want to set. 0 for no permissions, 1 for execute only, 2 for write only, 3 for write and execute, 4 for read only, 5 for read and execute, 6 for read and write, 7 for read, write, execute: ");
    int perm;
    scanf("%o", &perm);

	struct stat filestat;

	stat(file, &filestat);

	//printing file creation time
	time_t creation_time = time(&filestat.st_birthtime);
	char *ct = ctime(&filestat.st_birthtime);
	printf("File birth time %s", ct);

	//time_t object representing time one hour before now
	time_t one_hour_ago = time(NULL)-3600;
	char *rt = ctime(&one_hour_ago);

	printf("Time one hour ago %s", rt);

	//if file creation time is after the time an hour ago, change permissions

	if (difftime(creation_time,one_hour_ago)>0)
	{
		const mode_t new_perm=perm;

		if (chmod(file, new_perm)==0)
		{
			printf("File permission changed successfully.\n");
		}
		else
		{
			perror("chmod");
    		return EXIT_FAILURE;
		}
		return EXIT_SUCCESS;
	}
	else
		printf("Creation date is not after the reference date.\n");

	return 0;
	

}