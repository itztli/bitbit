#include <stdio.h>
#include <stdlib.h>
#include "bit.h"
#include "numeric.h"
#include <time.h>
#include <math.h>
#include <gmp.h>

/*
Modificar el codigo para que mediante la linea de argumentos les pasen la cantidad de espacios a asignar en la memoria RAM y dentro del programa reserven esa N cantidad de enteros en la variable mypointer y a traves de un for asignen valores secuenciales de 0 a N y los imprima.
*/


int int_pow(int base, int exp)
{
    int result = 1;
    while (exp)
    {
        if (exp % 2)
           result *= base;
        exp /= 2;
        base *= base;
    }
    return result;
}


unsigned long long int ullint_pow(unsigned long long int base, int exp)
{
    unsigned long long int result = 1;
    int i;

    result = 1;
    
    for(i = 1; i<=exp;i++){
      result *= base;
    }

    return result;

}



int main(int argn, char **argv){
  //char c; // 1 byte = 8 bits
  int i;  // 4 bytes = 32 bits
  //double d; // 8 bytes = 64 bits
  //char *msg;
  int key;
  //int p,q;
  //int n;
  //int phi;
  int e,d;
  int x,y;

  unsigned long long int msg;
  unsigned long long int c;

  mpz_t  big_n;
  mpz_t p,q,n,phi,p1,q1;

    
  mpz_init (p);
  mpz_init (q);
  mpz_init (n);
  mpz_init (p1);
  mpz_init (q1);
  mpz_init (phi);

  //mpz_init_set_str (big_n, "1283749832749832749832748324876498769843659874365398476598743265874365984365984377364873264984376869087698769876987687698768768768768769876987698769876987698769898374598743698736487346587346548743658743658743659843765843765874326587436589324687326498726498648732698437687432658743659843765874365987436523456", 0);
  gmp_computePrime(p,2048);
  gmp_computePrime(q,2048);
  
  gmp_printf ("p=%Zd\n", p);
  gmp_printf ("q=%Zd\n", q);

  mpz_mul (n, p, q);

  gmp_printf ("n=%Zd\n", n);

  mpz_sub_ui (p1, p, 1);
  mpz_sub_ui (q1, q, 1);
  mpz_mul (phi, p1, q1);
  gmp_printf ("phi=%Zd\n", phi);
  
  mpz_clear (phi);  
  mpz_clear (n);  
  mpz_clear (p);  
  mpz_clear (q);  
  mpz_clear (p1);  
  mpz_clear (q1);  

  
//////  
//////   srand(time(NULL));   // Initialization, should only be called once.
//////
//////  do{
//////  
//////    p = computePrime(16);
//////    q = computePrime(16);
//////
//////
//////    
//////    n = p*q;
//////    phi = (p-1)*(q-1);
//////    e = computePrime(phi);
//////    d =-1;
//////    
//////    for(x=2;x<phi;x++){
//////      y =1 + x*phi;
//////      if( (y % e) == 0){
//////	d = (1 + x*phi) / e;
//////	break;
//////      }
//////    }
//////  }while(d < 0);
//////  
//////  
//////  printf("d\te\tphi\tn\tp\tq\n");
//////  printf("%i\t%i\t%i\t%i\t%i\t%i\n",d,e,phi,n,p,q);
//////
//////  msg = (unsigned long long int)2;  //(unsigned long long int)packing('h','o','l','a');
//////  
//////  printf("msg=%llu\n",msg);
//////
//////
//////  printf("test=%llu\n",ullint_pow(2,43));
//////
//////  //encriptar
//////
//////  c = ullint_pow(msg,e) % n;
//////
//////  printf("c=%llu \n",c);
//////  //desencriptar
//////  msg = (ullint_pow(c,d)) % n;
//////  printf("msg=%llu\n",msg);
//////
//////
  
//
//
//  key = 2;
//  msg = malloc(4);
//  
//  c = 0x01; //''; //BIG 1000 0000   LIT 0000 0001
//  i = 1024;
//  d = 3.1416;
//
//  
//  //printf("%i\t%i\t%le\n",c,i,d);
//
//  //print_bit(c);
//
//  //printf("%i\n",sizeof(i));
//
//  i = packing('h','o','l','a');
//
//  i = i*key;
//  printf("%i\n",i);
//  unpacking(i,msg);
//  printf("%s\n",msg);
//  i = i/key;  
//  unpacking(i,msg);
//  printf("%s\n",msg);
//  packInt2Double(1, 2);  
//  free(msg);
//  
////  char *mystring;
////  int *mypointer;
////  // printf("%s\n",argv[1]); 
////  if (argn < 2){
////    printf("Error: You need pass an argument.\n");
////    return 0;
////  }
////  mystring = malloc(1024);        //sizeof(argv[1]));
////  sprintf(mystring,"%s",argv[1]);
////  printf("%s\n",mystring);
////  printf("%p\n",&mystring);
////  free(mystring);
  return 1;
}
