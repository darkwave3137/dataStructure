#include<stdio.h>
#include<stdlib.h>
#include"SqList.h"

void move(SqList *&L){
    int i = 0, k = L -> length - 1;
    while(k > i){
        if(L -> data[k] % 2 == 1){
            int tmp = L -> data[i];
            L -> data[i++] = L -> data[k];
            L -> data[k] = tmp;
        }
        else k--;
    }
}

int main(void){
    ElemType a[] = {
        1,2,3,4,5,6,7,8
    };
    SqList *L;
    CreateList(L, a, 8);
    move(L);
    DispList(L);
    return 0;
}
