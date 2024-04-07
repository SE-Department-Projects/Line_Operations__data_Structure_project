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
    int c = 0, flag = 0;
    pn = pl->head;
    while (pn)
    {
        if (pn == pl->current)
        {
            flag = 1;
            pn = pn->next;
            continue;
        }
        if (flag == 0)
            c++;
        else
            c--;
        pn = pn->next;
    }
    return c;
}

int isFoundInRight(DubList *pl)
{
    ListNode *pn1, *pn2;
    pn1 = pl->head;
    pn2 = pl->current->next;

    while (pn1 != pl->current) // not end of the first part
    {
        while (pn2)
        {
            if (pn1->entry != pn2->entry)
            {
                pn2 = pn2->next; // if equals to null will retrun zero
            }
            else // the two chars are equal
            {
                pn1 = pn1->next;
                pn2 = pl->current->next; // return to the second part
                break;
            }
            if (!pn2)
                return 0;
        }
    }

    return 1;
}


int isMirror(DubList *pl)
{

    if (pl == NULL || pl->head == NULL || pl->tail == NULL)
        return 0;

    ListNode *left = pl->head;
    ListNode *right = pl->tail;


    int size = 0;// Determine the size of the list
    ListNode *tmp = pl->head;
    while (tmp != NULL) {
        size++;
        tmp = tmp->next;
    }

    // Traverse the list and check if it's a mirror
    for (int i = 0; i < size/2; i++) {
        if (left->entry != right->entry) {
            return 0;
        }
        left = left->next;
        right = right->prev;
    }

    return 1; // It's a mirror
}

int isIdentical (DubList *pl)
{
    ListNode *right = pl->head;
    ListNode *left = pl->current->next;

    while(right->entry != ':' && left != NULL)
    {
        if(right->entry != left->entry) // compare characters from right of : with those from left
            return 0; // found that characters are not identical
        right = right->next;
        left = left->next;
    }
    return 1; // found both sides to be identical
}
