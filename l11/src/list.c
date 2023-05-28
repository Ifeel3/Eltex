
#include "list.h"

#define uint32_t unsigned int

char* createString(char* str) {
	char* result;
	size_t len;

	if (str == NULL)
		return NULL;
	len = strlen(str);
	result = (char*)calloc(sizeof(char), len + 1);
	if (result == NULL)
		return NULL;
	memcpy(result, str, len);
	return result;
}

void deleteList(list_t* src) {
	if (src == NULL)
		return;
	if (src->m_firstName != NULL) free(src->m_firstName);
	if (src->m_secondName != NULL) free(src->m_secondName);
	free(src);
}

void deleteAll(list_t** head) {
	list_t *current, *next;

	if (head == NULL || (*head) == NULL)
		return;
	current = (*head);
	next = NULL;
	while (current != NULL) {
		next = current->m_next;
		free(current);
		current = next;
		next = NULL;
	}
	(*head) = NULL;
}

list_t* createList(char* firstName, char* secondName, int number) {
	list_t* result;

	result = (list_t*)malloc(sizeof(list_t));
	if (result == NULL)
		return NULL;
	result->m_firstName = NULL;
	result->m_firstName = createString(firstName);
	result->m_secondName = NULL;
	result->m_secondName = createString(secondName);
	result->m_number = number;
	result->m_next = NULL;
	if (result->m_firstName == NULL || result->m_secondName == NULL) {
		deleteList(result);
		result = NULL;
	}
	return result;
}

list_t* addToEnd(list_t** head, list_t* src) {
	list_t* tmp;

	if (head == NULL || src == NULL)
		return NULL;
	if ((*head) == NULL) {
		(*head) = src;
		return src;
	}
	tmp = (*head);
	while (tmp->m_next != NULL) {
		tmp = tmp->m_next;
	}
	tmp->m_next = src;
	return src;
}

void printOne(list_t* src) {
	if (src == NULL)
		return;
	printf("%s %s %d\n", src->m_firstName, src->m_secondName, src->m_number);
}

void printAll(list_t** head) {
	list_t* tmp;
	unsigned int i;

	if (head == NULL || (*head) == NULL)
		return;
	tmp = (*head);
	i = 1;
	while (tmp != NULL) {
		printf("%d.", i);
		printOne(tmp);
		tmp = tmp->m_next;
		++i;
	}
}

list_t* findByName(list_t** head, char* fisrtName, char* secondName) {
	list_t* tmp;

	if (head == NULL || (*head) == NULL || fisrtName == NULL || secondName == NULL)
		return NULL;
	tmp = (*head);
	while (tmp != NULL) {
		if (strcmp(fisrtName, tmp->m_firstName) == 0 && strcmp(secondName, tmp->m_secondName) == 0)
			return tmp;
		tmp = tmp->m_next;
	}
	return NULL;
}

list_t* findByNumber(list_t** head, int number) {
	list_t* tmp;

	if (head == NULL || (*head) == NULL)
		return NULL;
	tmp = (*head);
	while (tmp != NULL) {
		if (tmp->m_number == number)
			return tmp;
		tmp = tmp->m_next;
	}
	return NULL;
}

#undef uint32_t