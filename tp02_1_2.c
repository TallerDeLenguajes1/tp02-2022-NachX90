#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20

void main(){
    srand((int)time(NULL));
    int i, vt[N], *p_vt;
    p_vt=&vt[0];
    for(i=0; i<N; i++)
    {
        *p_vt=1+rand()%100;
        printf("%d ", *p_vt);
        p_vt++;
    }
}