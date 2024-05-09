#ifndef DOUBLELINKEDLIST_H_INCLUDED
#define DOUBLELINKEDLIST_H_INCLUDED

typedef char ListEntry;

typedef struct listnode
{

    struct listnode *next, *prev;
    ListEntry entry;
} ListNode;

typedef struct
{

    ListNode *current, *head, *tail;

    int currentPos, size;
} DubList;

void CreateList(DubList *pl);
int ListEmpty(DubList *pl);
int ListFull(DubList *pl);
int ListSize(DubList *pl);
void InsertList(DubList *pl, ListEntry e, int pos);
void DestroyList(DubList *pl);
void TraverseList(DubList *pl, void (*pf)(ListEntry));
void TraverseListOpp(DubList *pl, void (*pf)(ListEntry));

// Methods

int FindColon(DubList *pl);
int Difference(DubList *pl);
int IsPartOfRight(DubList *pl);
int IsFoundInRight(DubList *pl);
int IsIdentical(DubList *pl);
int IsMirror(DubList *pl);

#endif // DOUBLELINKEDLIST_H_INCLUDED
