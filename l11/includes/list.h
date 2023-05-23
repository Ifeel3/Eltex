#ifndef LIST_H
# define LIST_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>

# define uint32_t unsigned int

typedef struct list_s {
    char* m_firstName;
    char* m_secondName;
    struct list_s* m_next;
    int m_number;
} list_t;

list_t* createList(char* firstName, char* secondName, int number);
list_t* addToEnd(list_t** head, list_t* src);
list_t* printAll(list_t** head, list_t* unused);
list_t* print(list_t** unused, list_t* src);
list_t* deleteAll(list_t** head, list_t* unused);

# undef uint32_t

#endif //LIST_H