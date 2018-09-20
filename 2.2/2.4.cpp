#include<stdio.h>
#include<stdlib.h>
#include"SqList.h"

void partitionl(SqList *&L){
    int i = 0, j = L -> length - 1;
    int p = L -> data[0];
    while(i < j){
        while(i < j && L -> data[j] >= p){
            j--;
        }
        L -> data[i] = L -> data[j];
        while(i < j && L -> data[i] < p){
            i++;
        }
        L -> data[j] = L -> data[i];
    }
    L -> data[i] = p;
}

int main(void){
    ElemType a[] = {
        5,5,2,4,1,6,7,8,2,4,3
    };
    SqList *L;
    CreateList(L, a, 11);
    partitionl(L);
    for(int i = 0; i < L -> length; i++){
        printf("%d ", L -> data[i]);
    }
    return 0;
}
