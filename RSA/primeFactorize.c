#include "factors.h"

/**
 * factorize - Factorises the number given and prints the factors.
 * @num: The number to be factorised.
 *
 * Return: Nothing(void).
 */
void factorize(mpz_t num)
{
	/**
	 * Using datatypes and functions for large numbers provided by
	 * GMP library.
	 */
	mpz_t divisor, quotient, mul, large_half;

	mpz_init2(divisor, 200);
	mpz_set_ui(divisor, 2);
	mpz_init2(quotient, 200);
	mpz_set_ui(quotient, 0);
	mpz_init2(mul, 200);
	mpz_set_ui(mul, 0);
	mpz_init2(large_half, 108);
	mpz_set_ui(large_half, 0);
	mpz_cdiv_q(large_half, num, divisor);
	mpz_add_ui(large_half, large_half, 1);


	while (mpz_cmp(divisor, large_half) != 0)
	{
		mpz_cdiv_q(quotient, num, divisor);
		mpz_mul(mul, quotient, divisor);
		if (mpz_cmp(mul, num) == 0)
		{
			if (isBothPrime(quotient, divisor))
			{
				gmp_printf("%Zd=%Zd*%Zd\n", num, quotient, divisor);
				return;
			}
		}
		mpz_add_ui(divisor, divisor, 1);
	}
}

/**
 * isBothPrime - Checks if both large numbers are prime numbers.
 * @num_1: First large number.
 * @num_2: Second large number.
 *
 * Return: 1 if both numbers are prime,
 * Otherwise 0 if one or none are prime.
 */
int isBothPrime(mpz_t num_1, mpz_t num_2)
{
	mpz_t divisor, large_half, remainder;
	int flag = 0;

	mpz_init2(divisor, 200);
	mpz_set_ui(divisor, 2);
	mpz_init2(large_half, 108);
	mpz_set_ui(large_half, 0);
	mpz_cdiv_q(large_half, num_1, divisor);
	mpz_add_ui(large_half, large_half, 1);
	mpz_init2(remainder, 32);
	while (mpz_cmp(divisor, large_half) != 0)
	{
		mpz_cdiv_r(remainder, num_1, divisor);
		if (mpz_cmp_ui(remainder, 0) == 0)
		{
			flag = 1;
			break;
		}
		mpz_add_ui(divisor, divisor, 1);
	}
	if (flag == 0)
	{
		mpz_set_ui(divisor, 2);
		while (mpz_cmp(divisor, large_half) != 0)
		{
			mpz_cdiv_r(remainder, num_1, divisor);
			if (mpz_cmp_ui(remainder, 0) == 0)
			{
				flag = 1;
				break;
			}
			mpz_add_ui(divisor, divisor, 1);
		}
	}
	else
		return (0);

	if (flag == 0)
		return (1);
	return (0);
}
