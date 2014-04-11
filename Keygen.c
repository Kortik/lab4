#define PATHKEY "/home/alex/lab4/fifoKey"
#define BUFSIZEKEY 10
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
int main(void)
{
	int pipe, i;
	char key[BUFSIZEKEY];
	if (mkfifo(PATHKEY, 0777)) {
		printf("Error\n");
		exit(-1);
	}
	pipe = open(PATHKEY, O_WRONLY);
	for (i = 0; i < BUFSIZEKEY; i++)
		key[i] = i + 48;
	write(pipe, key, BUFSIZEKEY);
	close(pipe);
}
