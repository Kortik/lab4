#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#define PATHTEXT "/home/alex/lab4/fifoText"
#define PATHKEY "/home/alex/lab4/fifoKey"
#define BUFSIZEKEY 10

int main(void)
{
	int pipeKey, pipeText, i, test;
	char key[BUFSIZEKEY];
	char *p;
	char buf;
	pipeKey = open(PATHKEY, O_RDONLY);
	for (i = 0; i < BUFSIZEKEY; i++)
			read(pipeKey, &key[i], 1);
	close(pipeKey);
	pipeText = open(PATHTEXT, O_RDONLY);
	for (i = 0; read(pipeText, &buf, 1); i++) {
		if (i == BUFSIZEKEY-1)
			i = 0;
		buf ^= key[i];
		write(STDOUT_FILENO, &buf, 1);
	}
	close(pipeText);

}


