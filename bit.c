/* Primary implementation of functions defined in argparse.h */
#include "bit.h"
#include <stdio.h>          // 0&0 > 0, 0&1 > 0, 1&0 > 0, 1&1 > 1
#include <stdlib.h>
#include <math.h>

int unpacking(int n, char *msg){
  //char msg[4];
  int MASK;
  int a;
  char c;

  MASK = 0xFF000000;
  a = (n & MASK) >> 24;
  MASK = 0x000000FF;
  a = a & MASK;
  c = (char)a;
  msg[0] = c;

  MASK = 0x00FF0000;
  a = (n & MASK) >> 16;
  MASK = 0x000000FF;
  a = a & MASK;
  c = (char)a;
  msg[1] = c;

 MASK = 0x0000FF00;
  a = (n & MASK) >> 8;
  MASK = 0x000000FF;
  a = a & MASK;
  c = (char)a;
  msg[2] = c;

  MASK = 0x000000FF;
  a = (n & MASK);
  //MASK = 0x000000FF;
  //a = a & MASK;
  c = (char)a;
  msg[3] = c;



  
  return 1;
  
}



int packing(char a, char b, char c, char d){
  int zip;
  int MASK;
  int A;

  zip = 0x00000000;
  //zip = AAAAAAAA BBBBBBBB CCCCCCCC DDDDDDDDD
  //         zip -> 00000000 00000000 00000000 00000000
  //a = AAAAAAAA -> 00000000 00000000 00000000 AAAAAAAA
  //             -> AAAAAAAA 00000000 00000000 00000000
  //b = BBBBBBBB -> 00000000 00000000 00000000 BBBBBBBB
  //             -> 00000000 BBBBBBBB 00000000 00000000


  //       XXXX XX10&
  //MASK   0000 0011
  //-----------------
  //       0000 0010
  
  MASK = 0x000000FF;
  A = (int)a & MASK ;
  A = A << 24;
  MASK = 0xFF000000;
  A = A & MASK;
  zip = zip | A;

  MASK = 0x000000FF;
  A = (int)b & MASK ;
  A = A << 16;
  MASK = 0x00FF0000;
  A = A & MASK; 
  zip = zip | A;

  MASK = 0x000000FF;
  A = (int)c & MASK ;
  A = A << 8;
  MASK = 0x0000FF00;
  A = A & MASK; 
  zip = zip | A;

  MASK = 0x000000FF;
  A = (int)d & MASK ;
  //A = A << 16;
  //MASK = 0x00FF0000;
  //A = A & MASK; 
  zip = zip | A;

  return zip;
}


int print_bit(char c){
  //255   -> 1111 1111
  int i;
  int mask = 0x0001; // 0000 0001 &
//                //255    1111 1111
//                //    --------------
//                //       0000 0001  -> 1
//
//  printf("%i\n", (mask & c)  );
//
//  mask = 0x0008;      // 0000 1000 &
//                //255    1111 1111
//                //    --------------
//                //       0000 1000  -> 2
//                //                  >> 3
//                //    --------------
//                //       0000 0001  -> 1
//
//  
//  printf("%i\n", (mask & c) >> 1  );
//

  mask = 0x0001;

  // 0000 0001 1
  // 0000 0010 2
  // 0000 0100 4
  // 0000 1000 8
  // var vis   ascii(int)   binaria    printf(complement a2)
  // c = ' ' = 255        = 1111 1111 = -1


  // +255 + X = 0  
  // +(+255,X) = 0
  // +(+255,-255) = 0
  // 255 - 255 = 0

  // CONJUNTO DE INSTRUCCIONES
  // Depende de cada procesador (amd64 -> intel de 64bits)

  // 64bits (operador), 64bits (var1), 64bits (var2)
  // 0x01, 0xFF , 0x01   (8bits)
  // 0   0  0  0   0001  1111111100000001
  // 128 64 32 16  8421 
  // -> LITTLE ENDIAND

  // 0x01
  // 1000 0000 (BIG ENDIAND)
  // 0000 0001 (LITTLE ENDIAND)
  

  // -> 0x00

  // Hex     bin  
  // 0xFF -> 1111 1111 + (-1)
  // 0x01 -> 0000 0001   (1)
  //------------------
  // 0x00  X 0000 0000

  // 0x00 -> 0000 0000


  
  // Int(a2)  Hex(8bits)   bin(8bits)  ASCII  decimal   
  //  -1        0xFF       1111 1111    ' '    255
  // REPRESENTACION SINTACTICA

  

  // binario    decimal    Hexadecimal
  // 0001    -> 1       -> 0x01
  // 0010    -> 2       -> 0x02
  // 0011    -> 3       -> 0x03
  // 0101    -> 5       -> 0x05
  // 1000    -> 8       -> 0x08
  // 1001    -> 9       -> 0x09
  // 1010    -> 10      -> 0x0A
  // 1011    -> 11      -> 0x0B
  // 1100    -> 12      -> 0x0C
  // 1101    -> 13      -> 0x0D
  // 1110    -> 14      -> 0x0E
  // 1111    -> 15      -> 0x0F
//0001 0000  -> 16      -> 0x10
//0101 0101             -> 0x55
//1010 1010             -> 0xAA
  



  
  
  printf("%c\t%i\t",c,c);
  
  for (i=0; i < 8; i++){ 
    printf("%i",(mask & c) >> i);
    mask = pow(2,i+1);
    //printf("%i\n",mask);
  }
  printf("\n");  
  
  return 1;
}


double packInt2Double(int a, int b){
  long long D;
  long long MASK = 0x00001;
  long long E;
  double r;
  
  //MASK = 0xFFFFFFFF00000000;
  E = (a << 32);// & MASK;

  D = (E | D);// & MASK;
  
  MASK = 0x00000000FFFFFFFF;
  D = b | D;

  r = (double)D;
  
  printf("%f\n",r);

  
  return r;
  
}
