#include "numeric.h"
#include <stdio.h>          // 0&0 > 0, 0&1 > 0, 1&0 > 0, 1&1 > 1
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <gmp.h>

//#define	RAND_MAX	1024

int gmp_computePrime(mpz_t rop, unsigned long max){
  gmp_randstate_t state;
  mpz_t seed;
  //mpz_t rop;
  mp_bitcnt_t n;
  FILE *fileptr;
  char *buffer;
  long int filelen;
  unsigned long a[20];

  fileptr = fopen("/dev/random", "rb");  // Open the file in binary mode

  //fseek(fileptr, 0, SEEK_END);          // Jump to the end of the file
  //filelen = ftell(fileptr);             // Get the current byte offset in the file
  //rewind(fileptr);                      // Jump back to the beginning of the file

  filelen=128;

  buffer = (char *)malloc(filelen * sizeof(char)); // Enough memory for the file
  fread(buffer, filelen, 1, fileptr); // Read in the entire file
  fclose(fileptr); // Close the file


  n = (mp_bitcnt_t)max;

  /* Initialize z and a */
  mpz_init (seed);
  gmp_randinit_mt(state);
  
  //printf("a[0]=%lu\n",a[0]);



  //mpz_import (seed, 20, 1, sizeof(a[0]), 0, 0, a);
  mpz_import (seed, 128, 1, sizeof(buffer[0]), 0, 0, buffer);
  //gmp_printf ("seed=%Zd\n", seed);
  gmp_randseed(state,seed);  
  //gmp_randinit_default (state);
  //printf("1\n");

  //mp_urandomb_ui()

  do{
    mpz_urandomb (rop, state, n);
    //gmp_printf ("rop=%Zd\n", rop);  
  }while(mpz_probab_prime_p (rop, 15) != 1);
  mpz_clear (seed);  
  free(buffer);
  return 1;
}


int computePrime(int max){
  int r;
  int i;
  int maxi;
  int prime;
  float r2;
  
  //srand(time(NULL));   // Initialization, should only be called once.
  
  
  do{ 
    r = ((float)rand()/(float)RAND_MAX)*max;//rand();
      //(int)(  ((float)rand())/((float)RAND_MAX))*((float)max);
           // Returns a pseudo-random integer between 0 and RAND_MAX.
    //printf("r=%i\n",r);
    maxi = (int)sqrt((float)r);
    //printf("maxi=%i\n",maxi);
    prime = 1;
    for (i=2; i <= maxi; i++){
      //printf("mod=%i\n",(r % i));
      if ( (r % i) == 0){
	prime = 0;
	break;
      }
    }
  }while(!(prime));

  return r;
}

