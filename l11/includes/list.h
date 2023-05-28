#ifndef LIST_H
# define LIST_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include "err.h"

# define uint32_t unsigned int

typedef struct list_s {
    char* m_firstName;
    char* m_secondName;
    struct list_s* m_next;
    int m_number;
} list_t;

list_t* createList(char* firstName, char* secondName, int number);
list_t* addToEnd(list_t** head, list_t* src);
void deleteList(list_t* src);
void deleteAll(list_t** head);
void printOne(list_t* src);
void printAll(list_t** head);
list_t* findByName(list_t** head, char* fisrtName, char* secondName);
list_t* findByNumber(list_t** head, int number);

# undef uint32_t

#endif //LIST_H