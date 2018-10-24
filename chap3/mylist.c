#include <stdio.h>
#include <stdlib.h>

typedef struct list {
    int item;
    struct list *next;
} list;

list *construct_list (int *a, int n) {
    list *next = NULL;
    for (int i = 0; i < n; i++) {
        list *node = NULL;
        node = malloc(sizeof(list));
        if (node != NULL) {
            printf("The address %p has been allocated successfully...\n", node);
            node->item = *(a+i);
            node->next = next;
            next = node;
        }
        else {
            printf("allocation failed!");
            return NULL;
        }
    }
    return next;
}

list *search_list(list *l, int element) {
    if (l == NULL) 
        return NULL;
    if (l->item == element)
        return l;
    else
        return (search_list(l->next, element));
}

void print_list (list *l) {
    while (l != NULL) {
        printf("%d->", l->item);
        l = l->next;
    }
    printf("NULL\n");
}

void insert_list(list **l, int x) {
    list *p;

    p = malloc(sizeof(list));
    if (p != NULL) {
        p->item = x;
        p->next = *l;
        printf("The address %p has been allocated successfully...\n", p);
        *l = p;
    }
    else
        printf("allocation failed!");
}

list *predecessor_list(list *l, int x) {
    if (l == NULL || l->next == NULL) {
        printf("Error: predecessor sought on null list.\n");
        return NULL;
    }

    if (l->next->item == x)
        return l;
    else
        return predecessor_list(l->next, x);
}

void delete_list(list **l, int x) {
    list *p;
    list *pred;
    
    p = search_list(*l, x);
    if (p != NULL) {
        pred = predecessor_list(*l, x);
        if (pred == NULL)
            *l = p->next;
        else
            pred->next = p->next;
        printf("The content of address %p has been freed successfully...\n", p);
        free(p);
        
    }
}

void free_list(list *l) {
    while (l != NULL) {
        list *fl = l->next;
        free(l);
        printf("The content of address %p has been freed successfully...\n", l);
        l = fl;
    }
}


int main (int argc, char* argv[]) {
    int aa[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    list *ml = construct_list(aa, 10);
    printf("the content of ml is %p\n", ml);
    printf("the address of ml is %p\n", &ml);
    print_list(ml);
    printf("%d\n", ml->item);
    printf("%d\n", ml->next->item);
    printf("%d\n", search_list(ml, 6)->item);
    insert_list(&ml, 10);
    print_list(ml);
    delete_list(&ml, 7);
    print_list(ml);
    delete_list(&ml, 10);
    print_list(ml);
    free_list(ml);
    return 0;
}