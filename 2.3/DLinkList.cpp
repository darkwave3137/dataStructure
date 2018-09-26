#include<stdio.h>
#include<stdlib.h>
#include"DLinkList.h"


void CreatListF(DLinkNode *&L, ElemType a[], int n){
    DLinkNode *p;
    L = (DLinkNode *)malloc(sizeof(DLinkNode));
    L -> prior = L -> next = NULL;
    for(int i = 0; i < n; i++){
        p = (DLinkNode *)malloc(sizeof(DLinkNode));
        p -> data = a[i];
        p -> next = L -> next;
        if(L -> next != NULL)
            L -> next -> prior = p;
        L -> next = p;
        p -> prior = L;
    }
}


void CreatListR(DLinkNode *&L, ElemType a[], int n){
    DLinkNode *p, *r = L;
    L = (DLinkNode *)malloc(sizeof(DLinkNode));
    for(int i = 0; i < n; i++){
        p = (DLinkNode *)malloc(sizeof(DLinkNode));
        p -> data = a[i];
        p -> prior = r;
        r -> next = p;
        r = p;
    }
    r -> next = NULL;
}

bool ListInsert(DLinkNode *L, int i, ElemType e){
    DLinkNode *p = L, *r;
    while(i-- && p != NULL){
        p = p -> next;
    }
    if(i != 0) return false;
    r = (LinkNode *)malloc(sizeof(LinkNode));
    p -> prior -> next = r;
    r -> prior = p -> prior;
    r -> next = p;
    p -> prior = r;
    return true;
}


bool ListDelete(DLinkNode *L, int i, ElemType &e){
    DLinkNode *p = L;
    while(i-- && p != NULL){
        p = p -> next;
    }
    if(i != 0) return false;
    p -> prior -> next = p -> next;
    p -> next -> prior = p -> prior;
    free(p);
    return true;
}



















