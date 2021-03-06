/*-------------------------------------------------------------
*
* a000045c.cpp
* 
* Fibonacci numbers: F[n] = F[n-1] + F[n-2]
* 
* OEIS a000045
*
*--------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    const int max = 25;

    unsigned int * a = (unsigned int*)malloc((max+1)*sizeof(unsigned int));

    int i = 0;

    unsigned int fn = 0;             // f(n)
    unsigned int fn1 = 1;            // f(n-1)
    unsigned int fn2 = 0;            // f(n-2)
    unsigned int n = 2;
    *(a + 0) = fn2;
    *(a + 1) = fn1;

    while (n < max) {
        fn = fn1 + fn2; 
        *(a + n) = fn;
        fn2 = fn1;
        fn1 = fn; 
        ++n; 
    }

    for (i = 0; i < max; ++i) {
        printf("%u    %u\n", i+1, *(a+i)); 
    }

    free(a);    
    return 0;
}

