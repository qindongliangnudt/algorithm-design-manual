#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

int main(int argc, char *argv[]) {
    int elements[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    List L = MakeEmpty();
    printf("The List L is Empty?:%d\n", IsEmpty(L));

    Position CurrentPosition = L;
    for (int i = 0; i < 10; i++){
        Position TmpCell = Insert(elements[i], L, CurrentPosition);
        CurrentPosition = TmpCell;
    }
    printf("The List L is Empty?:%d\n", IsEmpty(L));
    PrintList(L);
    Position P2 = Find(2, L);
    if ( P2 != NULL) {
        printf("Bingo, The content %d is stored in the address %p\n", Retrieve(P2), P2);
    }
    else
        printf("The content is not found...\n");
    Delete(2, L);
    P2 = Find(2, L);
    if ( P2 != NULL) {
        printf("Bingo, The content %d is stored in the address %p\n", Retrieve(P2), P2);
    }
    else
        printf("The content is not found...\n");
    
    PrintList(L);
    DeleteList(L);
    return 0;
}