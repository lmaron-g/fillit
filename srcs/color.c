#include <stdio.h>

#define RESET   "\033[0m"
#define RED     "\033[1;31m"
#define YELLOW  "\033[1;33m"
#define WHITE   "\033[1;37m"
#define A "\033[31m"
#define B "\033[32m"
#define C "\033[33m"
#define D "\033[34m"
#define E "\033[35m"
#define F "\033[36m"
#define G "\033[37m"
#define H "\033[38m"
#define I "\033[39m"
#define J "\033[40m"
#define K "\033[41m"
#define L "\033[42m"
#define M "\033[43m"
#define N "\033[44m"
#define O "\033[45m"
#define P "\033[46m"
#define Q "\033[47m"
#define R "\033[48m"
#define S "\033[19m"
#define U "\033[20m"
#define V "\033[21m"
#define W "\033[22m"
#define X "\033[23m"
#define Y "\033[24m"


int			main(int c, char **v)
{
	printf("%sYELLOW TEXT%s\n",    YELLOW, RESET);
	write(1, RED);
	write(1, "RED TEXT\n");
	write(1, A);
	write(1, "TEXT\n");
	write(1, RESET);
	write(1, B);
	write(1, "TEXT\n");
	write(1, RESET);
	
	write(1, C);
	write(1, "TEXT\n");
	write(1, RESET);
	write(1, D);
	write(1, "TEXT\n");
	write(1, RESET);
	
	write(1, E);
	write(1, "TEXT\n");
	write(1, RESET);
	write(1, F);
	write(1, "TEXT\n");
	write(1, RESET);
	
	write(1, G);
	write(1, "TEXT\n");
	write(1, RESET);
	write(1, H);
	write(1, "TEXT\n");
	write(1, RESET);
	
	write(1, I);
	write(1, "TEXT\n");
	write(1, RESET);
	write(1, J);
	write(1, "TEXT\n");
	write(1, RESET);
	
	write(1, K);
	write(1, "TEXT\n");
	write(1, RESET);
	write(1, L);
	write(1, "TEXT\n");
	write(1, RESET);
	

	write(1, RESET);
	return (0);
}
