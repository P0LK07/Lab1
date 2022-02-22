#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matrix.h"

void print(Row* r, char* vector_name);
{
    int i;
    if(!vector_name)
        vector_name = "\0";        
    printf("Vector %s = {", vector_name);
    for(i = 0; i < r->len; i++)
    {
        printf("%d, ", (r->address)[i]);
    }
    printf("}\n");
}
void _insert(Row* array,int* element, size_t index)
{
    Row* a = array;
    int e = element[0];
    if(index <= a->len && index >= 0)
    {
        a->len++;
        a->address = realloc(a->address, sizeof(int*) * a->len);
        a->address =  (a->len - 1 - index > 0 ? memcpy(a->address[index + 1], a->address[index], (a->len - 1 - index)*sizeof(int*) : a->address);
        a->address[index] = e;
    }

}
Row* _initrow(){
    Row* row = malloc(sizeof(Row))
    row->address = calloc(sizeof(int), 1)
    row->len = 0;
    return row;
}
int find(int* a, int f, int len)
{
    int i;
    for(i = 0; i < len; i++)
        if(a[i] == f)
            return i;
    return -1;
}

int counteq(Row* r)
{
    int* uniq = calloc(sizeof(int), r->len);
    int lenu = 0, i = 0;
    for(i = 0; i < r->len; i++)
    {
        if(find(uniq, r->address[i], lenu) == -1)
        {
            uniq[lenu] = r->address[i];
            lenu++;
        }
    }
    uniq = realloc(uniq,sizeof(int)*lenu);
    int ans = 0, f;

    int* cnt = calloc(sizeof(int), lenu);   
    for(i = 0; i < r->len; i++)
    {
        f = ++cnt[find(uniq, r->address[i], lenu)];
        
        ans = f > ans ? f : ans;
    }
    free(cnt);
    free(uniq);
    return ans;
}

Row* task(Matrix* matrix){
    Row* ans = _initrow();
    int i;
    int* f = malloc(sizeof(int));
    for(i = 0; i < matrix->len; i++)
    {
        f[0] = counteq(matrix->address[i]);
        _insert(ans, f,ans->len);
    }
    free(f);
    return ans;
}

Matrix* enter(){
    Matrix* m = malloc(sizeof(Matrix));
    int i,j;
    m->address = NULL;
    m->len = 0;
    printf("Enter number of rows: ");
    scanf("%d", &(m->len));
    for(i = 0; i < m->len; i++){
        printf("Enter %d row column number: ", i + 1);
        m[i] = calloc(sizeof(Row));
        scanf("%d", &((m[i])->len));
        m[i]->address = calloc(sizeof(int), m[i]->len);
        printf("Enter row: ");
        for(j = 0; j < m[i]->len)
            scanf("%d",&(m[i]->address[j]));

    }
    return m;
}
void remove(void* a, int op){
    switch(op)
    {
        case 1:
            Row* ptr = ((Matrix*)a)->address;
            int len = ((Matrix*)a)->len,i;
            for(i = 0; i < len; i++)
            {
                remove(&ptr[i],2);
            }
            break;
        case 2:
            int* address = ((Row*)a)->address;
            free(address);
            break;
        default:
            printf("Error: Invalid struct\n");
    }
}