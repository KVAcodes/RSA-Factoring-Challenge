#include "factors.h"

/**
 * main - Entry point of execution for the factors program.
 * @argc: No of command line arguments.
 * @argv: An array of the command line arguments.
 *
 * Return: EXIT_SUCCESS on success,
 *	   Otherwise EXIT_FAILURE on failure.
 */
int main(int argc, char **argv)
{
	char buffer[128];
	FILE *test;
	mpz_t value;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: factors <file>\n");
		exit(EXIT_FAILURE);
	}
	test = fopen(argv[1], "r");
	if (!test)
		exit(EXIT_FAILURE);

	while (fgets(buffer, sizeof(buffer), test))
	{
		mpz_init2(value, 200);
		mpz_set_str(value, buffer, 10);
		factorize(value);
	}

	fclose(test);
	exit(EXIT_SUCCESS);
}
