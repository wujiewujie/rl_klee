/*
 * First KLEE tutorial: testing a small function
 */

#include <klee/klee.h>


int get_sign(int x) {
    if(x>0){
        if(x<1){
            klee_stop();
            return 0;
        }else{
            return 1;
        }
    }else{
        if(x<-1){
            return 2;
        }else{
            return 3;
        }
    }
}

int main() {
    klee_connect();
    int a;
    klee_make_symbolic(&a, sizeof(a), "a");
    return get_sign(a);
} 
