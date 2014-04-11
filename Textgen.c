#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#define PATHTEXT "/home/alex/lab4/fifoText"
int main(void)
{
	int pipe, i;
	char buf;
	if (mkfifo(PATHTEXT, 0777)) {
		printf("Error\n");
		exit(-1);
	}
	pipe = open(PATHTEXT, O_WRONLY);
	while (read(STDIN_FILENO, &buf, 1)) {
		if (buf == '\n') {
			close(pipe); exit(0);
			}
		write(pipe, &buf, 1);
	}
	close(pipe);
	exit(0);
}
