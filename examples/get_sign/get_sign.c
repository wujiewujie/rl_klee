/*
 * First KLEE tutorial: testing a small function
 */

#include <klee/klee.h>

__attribute__((always_inline)) int get_sign(int x) {
  if (x == 0)
     return 0;
  
  if (x < 0){
      klee_stop();
      return -1;
  }
  else 
     return 1;
} 

int main() {
    klee_connect();
  int a;
  klee_make_symbolic(&a, sizeof(a), "a");
  return get_sign(a);
}
