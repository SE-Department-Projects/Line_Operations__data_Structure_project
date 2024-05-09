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
    ListNode *pn = (ListNode *)malloc(sizeof(ListNode));
    int i;
    pn->entry = e;
    pn->next = NULL;
    pn->prev = NULL;

    if (!pl->tail)
    {                  // if the list is empty
        pl->head = pn; // head point to pn
        pl->tail = pn; // tail point to pn
    }
    else
    {                           // list not empty
        pl->current = pl->head; // the current points to first element
        if (pos == 0)
        { // if the insertion in first pos
            pn->next = pl->current;
            pl->current->prev = pn;
            pl->head = pn;
        }
        else
        { // if insertion is not in first pos
            for (i = 0; i < pos - 1; i++)
            {
                pl->current = pl->current->next; // make the current point to the one node before the insertion
                pl->currentPos++;
            }
            pn->prev = pl->current;
            pn->next = pl->current->next;
            pl->current->next = pn;
            if (pos == pl->size) // if the insertion is at the end
                pl->tail = pn;   // tail points to the new node
            else
                pn->next->prev = pn;
        }
    }
    pl->size++;
}

void DestroyList(DubList *pl)
{
    ListNode *pn;
    while (pl->head)
    {
        pn = pl->head;
        pl->head = pl->head->next;
        free(pn);
    }
}

void TraverseList(DubList *pl, void (*pf)(ListEntry))
{ // not used
    ListNode *pn = pl->head;
    while (pn)
    {
        (*pf)(pn->entry);
        pn = pn->next;
    }
}

void TraverseListOpp(DubList *pl, void (*pf)(ListEntry))
{ // not used
    ListNode *pn = pl->tail;
    while (pn)
    {
        (*pf)(pn->entry);
        pn = pn->prev;
    }
}

// METHODS

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

int IsFoundInRight(DubList *pl)
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

int IsPartOfRight(DubList *pl)
{
    ListNode *pn, *pn2;
    pn = pl->head;
    pn2 = pl->current->next;

    while (pn2)
    {
        if (pn->entry != pn2->entry)
        {
            pn = pl->head;
            pn2 = pn2->next;
        }
        else
        {
            pn = pn->next;
            pn2 = pn2->next;
        }
        if (pn->entry == ':')
            return 1;
    }
    return 0;
}

int IsIdentical(DubList *pl)
{
    ListNode *right = pl->head;
    ListNode *left = pl->current->next;

    while (right->entry != ':' && left != NULL)
    {
        if (right->entry != left->entry) // compare characters from right of : with those from left
            return 0;                    // found that characters are not identical
        right = right->next;
        left = left->next;
    }
    return 1; // found both sides to be identical
}

int IsMirror(DubList *pl)
{

    if (pl == NULL || pl->head == NULL || pl->tail == NULL)
        return 0;

    ListNode *left = pl->head;
    ListNode *right = pl->tail;

    int size = 0; // Determine the size of the list
    ListNode *tmp = pl->head;
    while (tmp != NULL)
    {
        size++;
        tmp = tmp->next;
    }

    // Traverse the list and check if it's a mirror
    for (int i = 0; i < size / 2; i++)
    {
        if (left->entry != right->entry)
        {
            return 0;
        }
        left = left->next;
        right = right->prev;
    }

    return 1; // It's a mirror
}
