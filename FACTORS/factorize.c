#include "factors.h"

/**
 * factorize - Factorises the number given and prints the factors.
 * @num: The number to be factorised.
 *
 * Return: Nothing(void).
 */
void factorize(mpz_t num)
{
	unsigned int inc = 1;
	mpz_t divisor, quotient, mul, large_half;

	mpz_init2(divisor, 200);
	mpz_set_ui(divisor, 2);
	mpz_init2(quotient, 200);
	mpz_set_ui(quotient, 0);
	mpz_init2(mul, 200);
	mpz_set_ui(mul, 0);
	mpz_init2(large_half, 100);
	mpz_set_ui(large_half, 0);
	mpz_cdiv_q(large_half, num, divisor);

	while (mpz_cmp(divisor, large_half) != 0)
	{
		mpz_cdiv_q(quotient, num, divisor);
		mpz_mul(mul, quotient, divisor);
		if (mpz_cmp(mul, num) == 0)
		{
			gmp_printf("%Zd=%Zd*%Zd\n", num, quotient, divisor);
			return;
		}
		mpz_add_ui(divisor, divisor, inc);
	}
}
