#include<stdio.h>
#include<stdlib.h>
#include"LinkList.h"

void delmaxnode(LinkNode *L){
    LinkNode *pre = L, *p = L;
    ElemType x = p -> next -> data;
    for(; p -> next != NULL; p = p -> next){
        if(p -> next -> data > x) {
            x = p -> next -> data;
            pre = p;
        }
    }
    p = pre -> next;
    pre -> next = p -> next;
    free(p);
}

int main(void){
    LinkNode *L;
    ElemType a[] = {
        256,5,7,34,6,8,9
    };
    CreatListR(L, a, 7);
    DispList(L);
    delmaxnode(L);
    DispList(L);
    return 0;
}
