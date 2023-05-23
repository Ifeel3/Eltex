#include <unistd.h>
#include "list.h"

//add
//print
//find
//del
//exit

typedef list_t* (*callBack)(list_t**, list_t*);

list_t* err(list_t** unused1, list_t*unused2) {
    (void) unused1;
    (void) unused2;
    return NULL;
}

list_t* quit(list_t** head, list_t* unused) {
    (void) unused;
    deleteAll(head, NULL);
    exit(0);
}

callBack selector(char type) {
    switch(type) {
        case '+': return addToEnd;
        case 'p': return printAll;
        case 'q': return quit;
        default: return err;
    }
}

int main(void) {
    list_t* head;

    head = NULL;
    selector('+')(&head, createList("lol", "kek", 1234567));
    selector('+')(&head, createList("pshe-pshe", "kurwa", 321432));
    selector('p')(&head, NULL);
    selector('q')(&head, NULL);
}