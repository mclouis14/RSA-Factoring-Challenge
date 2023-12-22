#include "factor.h"

/**
 * factorize - Factorizes a number and prints the factorization.
 * @n: The number to factorize.
 */
void factorize(int n)
{
        int i;

        for (i = 2; i <= n / 2; i++)
        {
                if (n % i == 0)
                {
                        printf("%d=%d*%d\n", n, i, n / i);
                        return;
                }
        }

        printf("%d is a prime number\n", n);
}

/**
 * main - This is the main function.
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line argument strings.
 *
 * Return: 0 on success, 1 on failure.
 */
int main(int argc, char *argv[])
{
	FILE *file;
	int num;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <file>\n", argv[0]);
		return (1);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (1);
	}

	while (fscanf(file, "%d\n", &num) == 1)
	{
		factorize(num);
	}

	fclose(file);
	return (0);
}
