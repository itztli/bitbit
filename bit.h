#ifndef BIT_H
#define BIT_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

  int print_bit(char c);

  int packing(char a, char b, char c, char d);

  int unpacking(int n, char *msg);

  double packInt2Double(int x, int y);
  
    //char* unpacking(int n);
  
#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif /* BIT_H */
