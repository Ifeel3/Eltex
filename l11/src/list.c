
#include "list.h"

#define uint32_t unsigned int

list_t* createList(char* fistName, char* secondName, int number) {
    list_t* newList = (list_t*)malloc(sizeof(list_t));
    newList->m_firstName = (char*)malloc(sizeof(char)*(strlen(fistName)+1));
    memset(newList->m_firstName, 0, strlen(fistName) + 1);
    memcpy(newList->m_firstName, fistName, strlen(fistName));
    newList->m_secondName = (char*)malloc(sizeof(char)*(strlen(secondName)+1));
    memset(newList->m_secondName, 0, strlen(secondName) + 1);
    memcpy(newList->m_secondName, secondName, strlen(secondName));
    newList->m_number = number;
    newList->m_next = NULL;
    return newList;
}

void deleteList(list_t* src) {
    free(src->m_firstName);
    free(src->m_secondName);
    free(src);
}

list_t* delete(list_t** head, list_t* src) {
    if (src == (*head)) {
        deleteList(*head);
        (*head) = src;
    } else {
        list_t* tmp = (*head);
        while(tmp != NULL && tmp->m_next != src) {
            tmp = tmp->m_next;
        }
        if (tmp->m_next == src) {
            list_t* next = tmp->m_next->m_next;
            deleteList(tmp->m_next);
            tmp->m_next = next;
        }
    }
    return NULL;
}

list_t* addToEnd(list_t** head, list_t* src) {
    if ((*head) == NULL) {
        (*head) = src;
        return NULL;
    }
    list_t* tmp = (*head);
    while(tmp != NULL && tmp->m_next != NULL) {
        tmp = tmp->m_next;
    }
    tmp->m_next = src;
    return NULL;
}

list_t* find(list_t** head, list_t* src) {
    (void) head;
    (void) src;
    return NULL;
}

void deleteAllLists(list_t** head) {
    list_t* current = (*head);
    list_t* next = NULL;
    while(current != NULL) {
        next = current->m_next;
        deleteList(current);
        current = next;
        next = NULL;
    }
    (*head) = NULL;
}

list_t* findByIndex(list_t** head, unsigned int num) {
    if (num == 0) return (*head);
    else {
        list_t* tmp = (*head);
        while(num > 0 && tmp != NULL) {
            tmp = tmp->m_next;
            --num;
        }
        return tmp;
    }
}

void printOne(list_t* src) {
    printf("%s %s %d\n", src->m_firstName, src->m_secondName, src->m_number);
}

list_t* printAll(list_t** head, list_t* unused) {
    (void) unused;
    list_t* tmp = (*head);
    for(int i = 0; tmp != NULL; ++i) {
        printf("%d.", i);
        printOne(tmp);
        tmp = tmp->m_next;
    }
    return NULL;
}

#undef uint32_t