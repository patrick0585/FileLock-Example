#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/file.h>
#include <math.h>
#include <string.h>

#define BALANCE "balance.dat"
#define LOCKFILE "balance.lock"

/*
 *	Returns the size of a file
 */
int getFileSize() {
	struct stat fileInfos;
	stat(BALANCE, &fileInfos);
	int fileSize = fileInfos.st_size;
	return fileSize;
}

/*
 *	Reads the balance from the file
 */
int getBalance() {

	int fileSize = getFileSize();
	size_t bytesRead = 0;
	int balance = 0;
	
	int fd = open(BALANCE, O_RDONLY);
	if ( fd == -1 ) {
		fprintf(stderr, "Cannot open file '%s'!\n",BALANCE);
		exit(1);
	}

	char *buffer = new char[fileSize + 1];	
	bytesRead = read(fd, buffer, fileSize);
	buffer[fileSize] = '\0';
	sscanf(buffer, "%d", &balance);
	close(fd);

	printf("The current balance is %d$\n",balance);

	return balance;
}

/*
 *	Updates the balance in the file
 */
ssize_t writeBalance(int balance) {

	int fd = open(BALANCE, O_WRONLY | O_CREAT);
	if ( fd == -1 ) {
		fprintf(stderr, "Cannot open file '%s'!\n",BALANCE);
		exit(1);
	}

	// The number of digits of the credit amount
	int digits = floor(log10(abs(balance)))+1;

	char b1[digits];
	sprintf(b1, "%d", balance);
	b1[digits] = '\0';
	char *p = b1;
	
	printf("The balance was increased to %d$\n", balance);

	ssize_t writtenBytes = write(fd, p, sizeof(b1));
    
	return writtenBytes;
}

int main(int argc, char *argv[]) {

#ifdef LOCK
	int lockFd = open(LOCKFILE, O_CREAT);
	if ( flock(lockFd, LOCK_EX) == -1 ) {
        std::cout << "ERROR\n";
    }
#endif

	for(int i=0; i<=3; i++) {
		int balance = getBalance();	
		balance += 20;
		writeBalance(balance);
        sleep(2);
    }

#ifdef LOCK
	unlink(LOCKFILE);
	flock(lockFd, LOCK_UN);
#endif
}
