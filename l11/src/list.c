#include "list.h"

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

void addList(list_t* head, list_t* src) {
    list_t* tmp = head;
    while(tmp->m_next != NULL) {
        tmp = tmp->m_next;
    }
    tmp->m_next = src;
}

void deleteAllLists(list_t* head) {
    list_t* current = head;
    list_t* next = NULL;
    while(current != NULL) {
        next = current->m_next;
        deleteList(current);
        current = next;
        next = NULL;
    }
    head = NULL;
}

list_t* findByIndex(list_t* head, unsigned int num) {
    if (num == 0) return head;
    else {
        list_t* tmp = head;
        while(num > 0 && tmp != NULL) {
            tmp = tmp->m_next;
            --num;
        }
        return tmp;
    }
}