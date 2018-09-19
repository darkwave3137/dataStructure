#include<stdio.h>
#include"SqList.h"
#include<stdlib.h>

void CreateList(SqList *&L, ElemType a[], int n){
    L = (SqList *)malloc(sizeof(SqList));
    for(int i = 0; i < n; i++){
        L -> data[i] = a[i];
    }
    L -> length = n;
}

void InitList(SqList *&L){
    L = (SqList*)malloc(sizeof(SqList));
    L -> length = 0;
}

void DestroyList(SqList *L){
    free(L);
}

void DispList(SqList *L){
    for(int i = 0; i < L -> length; i++){
        printf("%d ", L -> data[i]);
    }
}


bool GetElem(SqList *L, int i, ElemType &e){
    if(L -> length < i || i < 1) return false;
    e = L -> data[i - 1];
    return true;
}

int LocateElem(SqList *L, ElemType e){
    for(int i = 0; i < L -> length; i++){
        if(L -> data[i] == e) return i + 1;
        return 0;
    }
}

bool ListInsert(SqList *L, int i, ElemType e){
    if(i > L -> length || i < 0) return false;
    L -> data[i - 1] = e;
    L -> length++;
    return true;
}

bool ListDelete(SqList *L, int i, ElemType e){
    if(i > L -> length || i < 0) return false;
    for(int j = L -> length - i; j > 0; j--){
        L -> data[i - 1] = L -> data[i];
        i++;
    }
    L -> length--;
    return true;
}
