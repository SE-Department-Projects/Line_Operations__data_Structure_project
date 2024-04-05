#include "DoubleLinkedList.h"

#include <stdlib.h>

int FindColon(DubList *pl)
{
    ListNode *pn;
    pn = pl->head;

    while(pn){
        if(pn->entry == ':'){
            pl->current = pn;
            return 1;
        }
        pn = pn->next;
    }
    return 0;
}


int Difference(DubList *pl)
{
    ListNode *pn;
    int c = 0,flag = 0;
    pn = pl->head;
    while(pn){
        if(pn == pl->current){
            flag = 1;
            pn = pn->next;
            continue;
        }
        if(flag == 0)
            c++;
        else
            c--;
        pn = pn->next;
    }
    return c;
}