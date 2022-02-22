#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matrix.h"

void print(Row* r)
{
    int i;      
    printf("Vector = {%d",(r->address)[0]);
    for(i = 1; i < r->len; i++)
    {
        printf(", %d", (r->address)[i]);
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
        a->address =  (a->len - 1 - index > 0 ? memcpy(&(a->address[index + 1]), &(a->address[index]), (a->len - 1 - index)*sizeof(int*)) : a->address);
        a->address[index] = e;
    }

}
Row* _initrow(){
    Row* row = malloc(sizeof(Row));
    row->address = calloc(sizeof(int), 1);
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
        f[0] = counteq(&(matrix->address[i]));
        _insert(ans, f,ans->len);
    }
    free(f);
    return ans;
}
void next()
{
    char c = 2;
    while(c != '\n')
        scanf("%c", &c);
}

void malfunc(int *len, char* enter_str)
{
    while(*len <= 0){
    printf("%s", enter_str);
    scanf("%d", len);
    if(*len <= 0)
        printf("Error occured, you have to input value more than 0 \n");
    next();
    }
}

Matrix* enter(){
    Matrix* m = calloc(sizeof(Matrix), 1);
    int i,j;
    m->address = NULL;
    m->len = 0;

    malfunc(&(m->len), "Enter number of rows: ");
    m->address = calloc(sizeof(Row),m->len*sizeof(Row*));
    char *str0 = calloc(sizeof(char), 90);
    for(i = 0; i < m->len; i++){
        sprintf(str0, "Enter %d row column number: ", i + 1);
        malfunc(&((m->address[i]).len), str0);
        (m->address[i]).address = calloc(sizeof(int), (m->address[i]).len);
        printf("Enter row: ");
        for(j = 0; j < (m->address[i]).len; j++)
            scanf("%d",&((m->address[i]).address[j]));
        next();
    }
    free(str0);
    return m;
}
void rem(void* a, int op){
    switch(op)
    {
        case 1:
            Row* ptr = ((Matrix*)a)->address;
            int len = ((Matrix*)a)->len,i;
            for(i = 0; i < len; i++)
            {
                rem(&ptr[i],2);
            }
            free(ptr);
            break;
        case 2:
            int* address = ((Row*)a)->address;
            free(address);
            break;
        default:
            printf("Error: Invalid struct\n");
    }
}