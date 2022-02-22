#include <stdio.h>
#include "matrix.h"
#include <stdlib.h>

int main(){
    Matrix* matrix = enter();
    Row* ans = task(matrix);
    rem(matrix, 1);
    print(ans);
    rem(ans, 2);
    free(ans);
    free(matrix);
    return 0;
}