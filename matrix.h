#ifndef MATRIX
#define MATRIX

typedef struct Row{
    int* address;
    int len;
} Row;

typedef struct Matrix{
    Row* address;
    int len;
} Matrix;

void print(Row* r);
Row* task(Matrix* matrix);
Matrix* enter();
void rem(void* a, int op);
#endif