
#include "list.h"

#define uint32_t unsigned int

char* createStr(char* str) {
    size_t len;
    char* result;

    len = strlen(str);
    result = (char*)malloc(len + 1);
    if (result == NULL)
        return NULL;
    memset(result, 0, len + 1);
    memcpy(result, str, len);
    return result;
}

list_t* createList(char* firstName, char* secondName, int number) {
    list_t* result;

    result = (list_t*)malloc(sizeof(list_t));
    if (result == NULL)
        return NULL;
    result->m_firstName = createStr(firstName);
    result->m_secondName = createStr(secondName);
    if (result->m_firstName == NULL || result->m_secondName == NULL) {
        if (result->m_firstName != NULL) free(result->m_firstName);
        if (result->m_secondName != NULL) free(result->m_secondName);
        free(result);
        return NULL;
    }
    result->m_number = number;
    result->m_next = NULL;
    return result;
}

void deleteList(list_t* src) {
    if (src->m_firstName != NULL) free(src->m_firstName);
    if (src->m_secondName != NULL) free(src->m_secondName);
    free(src);
}

list_t* deleteAll(list_t** head, list_t* unused) {
    (void) unused;
    list_t *current, *next;

    current = (*head);
    next = NULL;
    while(current != NULL) {
        next = current->m_next;
        deleteList(current);
        current = next;
        next = NULL;
    }
    return NULL;
}

list_t* addToEnd(list_t** head, list_t* src) {
    list_t* tmp;
    
    if ((*head) == NULL) {
        (*head) = src;
        return NULL;
    } else {
        tmp = (*head);
        while(tmp->m_next != NULL) {
            tmp = tmp->m_next;
        }
        tmp->m_next = src;
        return NULL;
    }
}

list_t* print(list_t** unused, list_t* src) {
    (void) unused;
    printf("%s %s %d\n", src->m_firstName, src->m_secondName, src->m_number);
    return NULL;
}

list_t* printAll(list_t** head, list_t* unused) {
    (void) unused;
    list_t* tmp;
    uint32_t counter;

    tmp = (*head);
    counter = 1;
    while(tmp != NULL) {
        printf("%d.", counter);
        print(NULL, tmp);
        tmp = tmp->m_next;
        ++counter;
    }
    return NULL;
}

#undef uint32_t