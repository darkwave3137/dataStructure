#include<stdio.h>
#include<stdlib.h>
#include"LinkList.h"

void CreatListF(LinkNode *&L, ElemType a[], int n){
    LinkNode *s;
    L = (LinkNode *)malloc(sizeof(LinkNode));
    L -> next = NULL;
    for(int i = 0; i < n; i++){
        s = (LinkNode *)malloc(sizeof(LinkNode));
        s -> next = L -> next;
        L -> next = s;
        s -> data = a[i];
    }
}


void CreatListR(LinkNode *&L, ElemType a[], int n){
    LinkNode *s, *r;
    L = (LinkNode *)malloc(sizeof(LinkNode));
    r = L;
    for(int i = 0; i < n; i++){
        s = (LinkNode *)malloc(sizeof(LinkNode));
        s -> data = a[i];
        r -> next = s;
        r = s;
    }
    r -> next = NULL;
}


void InitList(LinkNode *&L){
    L = (LinkNode *)malloc(sizeof(LinkNode));
    L -> next = NULL;
}

void DestroyList(LinkNode *L){
    LinkNode *p = L;
    while(p != NULL){
        free(L);
        L = p;
        p = p -> next;
    }
    free(L);
}


bool ListEmpty(LinkNode *L){
    return L -> next == NULL;    
}


int ListLength(LinkNode *L){
    int n = 0;
    LinkNode *r = L -> next;
    while(r != NULL){
        r = r -> next;
        n++;
    }
}

void DispList(LinkNode *L){
    LinkNode *r = L -> next;
    while(r != NULL){
        printf("%d ", r -> data);
        r = r -> next;
    }
    printf("\n");
}

bool GetElem(LinkNode *L, int i, ElemType &e){
    LinkNode *r = L;
    for(; i > 0; i--){
        if(r == NULL) return false;
        r = r -> next;
    }
    e = r -> data;
    return true;
}


int LocateElem(LinkNode *L, ElemType e){
    int i = 1;
    LinkNode *r = L -> next;
    while(r != NULL && L -> data != e){
        i++;
    }
    if(r == NULL) return 0;
    else return i;
}


bool ListInsert(LinkNode *L, int i, ElemType e){
    LinkNode *p = L, *s;
    if(i < 0) return false;
    for(int j = i - 1; j > 0; j--){
        if(p == NULL) return false;
        p = p -> next;
    }
    s = (LinkNode *)malloc(sizeof(LinkNode));
    s -> data = e;
    s -> next = p -> next;
    p -> next = s;
    return true;
}


bool ListDelete(LinkNode *L, int i, ElemType &e){
    LinkNode *p = L, *s;
    if(i < 0) return false;
    for(int j = i - 1; j > 0; j--){
        if(p -> next == NULL) return false;
        p = p -> next;
    }
    if(L -> next == NULL) return false;
    s = p -> next;
    e = s -> data;
    p -> next = p -> next -> next;
    free(s);
    return true;
}














