#include "DoubleLinkedList.h"
#include <stdlib.h>


void CreateList(DubList *pl)
{
    pl->current = NULL;
    pl->head = NULL;
    pl->tail = NULL;
    pl->currentPos = 0;
    pl->size = 0;
}

int ListEmpty(DubList *pl) // not used
{
    return (pl->size == 0);
}


int ListFull(DubList *pl) // not used
{
    return 0;
}

int ListSize(DubList *pl) // not used
{
    return pl->size;
}

void InsertList(DubList *pl, ListEntry e, int pos)
{
    ListNode *pn = (ListNode*)malloc(sizeof(ListNode));
    int i;
    pn->entry = e;
    pn->next = NULL;
    pn->prev = NULL;

    if(!pl->tail){ // if the list is empty
        pl->head = pn; // head point to pn
        pl->tail = pn; // tail point to pn
    }
    else{ // list not empty
        pl->current = pl->head; // the current points to first element
        if(pos == 0){ // if the insertion in first pos
            pn->next = pl->current;
            pl->current->prev = pn;
            pl->head = pn;
        }
        else{ // if insertion is not in first pos
            for(i = 0; i < pos-1; i++){
                pl->current = pl->current->next; // make the current point to the one node before the insertion
                pl->currentPos++;
            }
            pn->prev = pl->current;
            pn->next = pl->current->next;
            pl->current->next = pn;
            if(pos == pl->size) // if the insertion is at the end
                pl->tail = pn; // tail points to the new node
            else
                pn->next->prev = pn;
        }
    }
    pl->size++;
}


void DestroyList(DubList *pl)
{
    ListNode *pn;
    while(pl->head){
        pn = pl->head;
        pl->head = pl->head->next;
        free(pn);
    }
}


void TraverseList(DubList *pl, void (*pf)(ListEntry)){ // not used
    ListNode *pn = pl->head;
    while(pn){
        (*pf)(pn->entry);
        pn = pn->next;
    }
}


void TraverseListOpp(DubList *pl, void (*pf)(ListEntry)){ // not used
    ListNode *pn = pl->tail;
    while(pn){
        (*pf)(pn->entry);
        pn = pn->prev;
    }
}
