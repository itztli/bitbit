#ifndef NUMERIC_H
#define NUMERIC_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include <gmp.h>

  int computePrime(int max);
  int gmp_computePrime(mpz_t rop, unsigned long max);
  
    //char* unpacking(int n);
  
#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif /* NUMERIC_H */
