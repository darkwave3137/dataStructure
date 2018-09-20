#include<stdio.h>
#include"SqList.h"
#include<stdlib.h>

ElemType a[10] = {
    1,2,2,3,3,3,4,4,4,4
};

void delnodel(SqList *&L, ElemType x){
    int k = 0;
    for(int i = 0; i < L -> length; i++){
        if(L -> data[i] == x) k++;
        else L -> data[i - k] = L -> data[i];
    }
    L -> length -= k; 
}


int main(void){
    SqList *L;
    L = (SqList *)malloc(sizeof(SqList));
    CreateList(L, a, 10);
    delnodel(L, 3);
    for(int i = 0; i < L -> length; i++){
        printf("%d ", L -> data[i]);
    }
    printf("\n");
    return 0;
}
