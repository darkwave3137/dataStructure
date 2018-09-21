#include<stdio.h>
#include<stdlib.h>
#include"LinkList.h"

void split(LinkNode *&L, LinkNode *&L1, LinkNode *&L2){
    LinkNode *r, *p = L -> next, *q;
    L1 = L;
    r = L1;
    InitList(L2);
    while(p != NULL){
        r -> next = p;
        r = p;
        p = p -> next;
        if(p != NULL){
            q = p -> next;
            p -> next = L2 -> next;
            L2 -> next = p;
            p = q;
        }
    }
    r -> next = NULL;

}

int main(void){
    ElemType a[] = {
        1,2,3,4,5,6,7,8,9,10
    };

    LinkNode *L, *L1, *L2;
    CreatListR(L, a, 10);
    split(L, L1, L2);
    DispList(L1);
    DispList(L2);
    return 0;
}
