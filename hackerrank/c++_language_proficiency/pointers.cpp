#include <bits/stdc++.h>
using namespace std;


int main () {

  int a = 10, b = 5;
  int *p, **q;
  p = &a;
  q = &p;
  printf("Value of a = %d\nAddress of &a = %p\n\n", a, &a);
  printf("Value of b = %d\nAddress of &b = %p\n\n",b, &b);
  printf ("Value of p = %p\nAddress of &p = %p\nValue pointed by *p = %d\n\n", p, (void *) &p, *p);
  printf ("Value of q = %p\nAddress of &q = %p\nValue in *q = %p\nValue pointed by **q = %d\nAddress of &(**q) = %p\n", q, &q, *q, **q, &(**q));
  return 0;
}