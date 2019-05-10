/*
 * First KLEE tutorial: testing a small function
 */

#include <klee/klee.h>
#include <stdio.h>
#include <time.h>
clock_t start,end;

int get_sign(int x) {
  if (x == 0)
     return 0;
  
  if (x < 0){
      end = clock();
      double endtime = (double)(end-start)/CLOCKS_PER_SEC;
      printf("total time:%f\n",endtime);
      klee_stop();
      return -1;
  }
  else 
     return 1;
} 

int main() {
    start = clock();
  int a;
  klee_make_symbolic(&a, sizeof(a), "a");
  return get_sign(a);
} 
