#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

struct Node {
    ElementType Element;
    Position Next;
};

List MakeEmpty() {
    Position Header;
    Header = malloc( sizeof(struct Node ) );
    if (Header == NULL) 
        perror("Out of space!!!");
    Header->Element = -1;
    Header->Next = NULL;
    return Header;
}

/* Return True if L is empty */
int IsEmpty(List L) {
    return L->Next == NULL;
}

/* Return True if P is the last position in L */
/* Parameter L is unused in this implementation */
int IsLast(Position P, List L) {
    return P->Next ==NULL;
}

/* Return Position of X in L; NULL if not found */
Position Find(ElementType X, List L) {
    Position P;

    P = L->Next;
    while (P != NULL && P->Element != X)
        P = P->Next;
    return P;
}

/* Delete first occurrence of X from a list */
/* Assume use of header node */

void Delete (ElementType X, List L) {
    Position P, TmpCell;

    P = FindPrevious(X, L);

    if (!IsLast(P, L)) {
        TmpCell = P->Next;
        P->Next = TmpCell->Next;
        free(TmpCell);
    }
}

/* If X is not found, then Next field of returned */
/* Position id NULL */
/* Assume a header */
Position FindPrevious (ElementType X, List L) {
    Position P;

    P = L;
    while (P->Next != NULL && P->Next->Element != X) {
        P = P->Next;
    }
    return P;
}

/* Insert (after legal position P) */
/* Header imple,metation assumed */
/* Parameter L is unused in this implementation */
Position Insert(ElementType X, List L, Position P) {
    Position TmpCell;

    TmpCell = malloc( sizeof(struct Node ) );
    if (TmpCell == NULL)
        perror("Out of Space!!!");

    TmpCell->Element = X;
    TmpCell->Next = P->Next;
    P->Next = TmpCell;
    return TmpCell;
}

void DeleteList(List L) {
    Position P, Tmp;
    
    P = L->Next;
    L->Next = NULL;
    while (P!=NULL) {
        Tmp = P->Next;
        free(P);
        P = Tmp;
    }
}

Position Header(List L) {
    return L;
}

Position First(List L) {
    return L->Next;
}

Position Advance(Position P) {
    return P->Next;
}

ElementType Retrieve(Position P) {
    return P->Element;
}

void PrintList(List L) {
    Position P = L->Next;
    while (P != NULL) {
        printf("%d->", P->Element);
        P = P->Next;
    }
    printf("NULL\n");
}