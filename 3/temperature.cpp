#include <iostream>

int main(int argc, char *argv[])
{
	int fahr, celcius;
	int lower, upper, step; 
	lower = atoi(argv[1]);
	upper = atoi(argv[2]);
	step = atoi(argv[3]);
	fahr=lower;

	while (fahr <= upper){
		celcius = 5 * (fahr -32)/9;
		std::cout << "fahr:" << fahr <<"\tcelsius:" << celcius << std::endl;
		fahr=fahr+step;
	}
	return 0;
}

