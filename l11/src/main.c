#include <unistd.h>
#include "list.h"

typedef list_t* (*func)(list_t**, list_t*);

list_t* err(list_t** unused1, list_t* unused2) {
    (void) unused1;
    (void) unused2;
    printf("err");
    return NULL;
}

list_t* exitSucces(list_t** head, list_t* unused) {
    (void) unused;
    deleteAllLists(head);
    exit(0);
    return NULL;
}

func selector(char type) {
    switch(type) {
        case '+': return addToEnd;
        case 'p': return printAll;
        case '-': return delete;
        case '?': return find;
        case 'q': return exitSucces;
        default: return err;
    }
}

//add
//print
//find
//del
//exit

int main(void) {
    list_t* head = NULL;
    selector('+')(&head, createList("lolkek", "cheburek", 123456));
    selector('+')(&head, createList("pshe-pshe", "kurwa", 123456));
    selector('+')(&head, createList("onotole", "lolchto", 123456));
    selector('p')(&head, NULL);
    selector('q')(&head, NULL);
}