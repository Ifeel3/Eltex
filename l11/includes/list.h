#ifndef LIST_H
# define LIST_H

#include <stdlib.h>
#include <string.h>

typedef struct list_s {
    char* m_firstName;
    char* m_secondName;
    struct list_s* m_next;
    int m_number;
} list_t;

list_t* createList(char* fistName, char* secondName, int number);
void deleteList(list_t* src);
void addList(list_t* head, list_t* src);
void deleteAllLists(list_t* head);
list_t* findByIndex(list_t* head, unsigned int num);

#endif //LIST_H