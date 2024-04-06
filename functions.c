#include "DoubleLinkedList.h"

#include <stdlib.h>

int FindColon(DubList *pl)
{
    ListNode *pn;
    pn = pl->head;

    while (pn)
    {
        if (pn->entry == ':')
        {
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