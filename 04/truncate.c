#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

int main() {
	// run time inputs
	char file[100];
	printf("Enter file path: ");
	scanf("%s", file);
	char date[80];
	printf("Reference date will be an hour ago. Press 'y' to proceed: ");
	scanf("%s", date);

	

	// opening file
	FILE* fp = fopen(file, "r");
	if (fp == NULL) {
		perror("File open failed");
		return 1;
	}

	fseek(fp, 0L, SEEK_END);
	off_t length = ftell(fp);
	fclose(fp);

	// getting file stats
	struct stat filestat;
	if (stat(file, &filestat) != 0) {
		perror("stat failed");
		return 1;
	}

	// use creation time directly
	time_t creation_time = filestat.st_birthtime;

	// prepare human-readable times
	char ct[100], rt[100];
	strcpy(ct, ctime(&creation_time));

	time_t one_hour_ago = time(NULL) - 3600;
	strcpy(rt, ctime(&one_hour_ago));

	// print time info
	printf("File birth time: %s", ct);
	printf("Time one hour ago: %s", rt);

	// compare and truncate
	if (difftime(creation_time, one_hour_ago) > 0) {
		truncate(file, length / 2);
		printf("File truncated to half its length.\n");
	} else {
		printf("Creation date is not after the reference date.\n");
	}

	return 0;
}
