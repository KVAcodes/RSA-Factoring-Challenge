#ifndef FACTORS_H
#define FACTORS_H

#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>
#include <limits.h>

void factorize(mpz_t num);
int isBothPrime(mpz_t num_1, mpz_t num_2);

#endif /* FACTORS_H */
