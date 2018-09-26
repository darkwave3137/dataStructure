#include<stdio.h>
#include<stdlib.h>
#include"LinkList.h"

void sort(LinkNode *L){
    LinkNode *p = L -> next, *pre = L, *q;
    L -> next = NULL;
    while(p != NULL){
        pre = L;
        while(pre -> next != NULL){
            if(p -> data < pre -> next -> data) break;
            pre = pre -> next;
        }
        q = p -> next;
        p -> next = pre -> next;
        pre -> next = p;
        p = q;
    }
}

int main(void){
    LinkNode *L;
    ElemType a[] = {
        3
    };
    CreatListR(L, a, 0);
    sort(L);
    DispList(L);
    return 0;
}
