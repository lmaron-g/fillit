#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int			valid_file(char *path);

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (valid_file(argv[1]))
			printf("V tsvet\n");
		else
			printf("NE V tsvet\n");
	}
	else printf("suka\n");
}
