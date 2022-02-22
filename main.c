#include <stdio.h>
#include "matrix.h"


int main(){
    Matrix* matrix = enter();
    Row* ans = task(matrix);
    rem(matrix, 1);
    print(ans,"-----------------------\nAnswer: \n");
    rem(ans, 2);
    return 0;
}