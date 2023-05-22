#ifndef LIST_H
# define LIST_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define uint32_t unsigned int

typedef struct list_s {
    char* m_firstName;
    char* m_secondName;
    struct list_s* m_next;
    int m_number;
} list_t;

list_t* createList(char* fistName, char* secondName, int number);
//void deleteList(list_t* src);
list_t* delete(list_t** head, list_t* src);
list_t* addToEnd(list_t** head, list_t* src);
void deleteAllLists(list_t** head);
list_t* find(list_t** head, list_t* src);
list_t* printAll(list_t** head, list_t* unused);
void printOne(list_t* src);

#undef uint32_t

#endif //LIST_H