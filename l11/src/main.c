#include <unistd.h>
#include <stdio.h>
#include "list.h"
#include "err.h"

//add
//print
//find
//del
//exit

void printWB(char* str) {
	write(1, str, strlen(str));
}

void addContact(list_t** head) {
	char buffer1[1025], buffer2[1025], buffer3[129];
	int num;

	memset(buffer1, 0, 1025);
	printWB("Enter Firstname: ");
	read(0, buffer1, 1024);
	memset(buffer2, 0, 1025);
	printWB("Enter Secondname: ");
	read(0, buffer2, 1024);
	memset(buffer3, 0, 129);
	printWB("Enter number: ");
	read(0, buffer3, 128);
	write(1, "\n", 1);
	num = atoi(buffer3);
	addToEnd(head, createList(buffer1, buffer2, num));
}

void findContactByName(list_t** head) {
	char buffer1[1025], buffer2[1025];

	memset(buffer1, 0, 1025);
	printWB("Enter Firstname: ");
	read(0, buffer1, 1024);
	memset(buffer2, 0, 1025);
	printWB("Enter Secondname: ");
	read(0, buffer2, 1024);
	printOne(findByName(head, buffer1, buffer2));
	printWB("\n");
}


void findContactByNumber(list_t** head) {
	char buffer[129];
	int num;

	memset(buffer, 0, 128);
	printWB("Enter number: ");
	read(0, buffer, 128);
	num = atoi(buffer);
	printOne(findByNumber(head, num));
	printWB("\n");
}

void deleteContactByIndex(list_t** head) {
	list_t *tmp, *tmp2;
	char buffer[129];
	int i;

	memset(buffer, 0, 129);
	printWB("Enter index: ");
	read(0, buffer, 128);
	i = atoi(buffer);
	if (head == NULL || (*head) == NULL)
		return;
	if (i < 1) return;
	if (i == 1) {
		tmp = (*head)->m_next;
		deleteList((*head));
		(*head) = tmp;
		return;
	}
	else {
		tmp = (*head);
		while (i > 2 && tmp->m_next != NULL) {
			--i;
			tmp = tmp->m_next;
		}
		if (tmp->m_next != NULL) {
			tmp2 = tmp->m_next->m_next;
			deleteList(tmp->m_next);
			tmp->m_next = tmp2;
		}
		return;
	}
}

int main(void) {
    list_t *head;
	char buffer[1025];

	head = NULL;
    while (1) {
		char* str = "1.Add contact\n2.Print all contcts\n3.Find contact by firstname and secondname\n4.Find contact by number\n5.Delete contact by index\n6.Exit\n\nSelect option: ";
		write(1, str, strlen(str));
		memset(buffer, 0, 1025);
		read(0, buffer, 1024);
		switch (buffer[0]) {
			case '1': addContact(&head);
				break;
			case '2': printAll(&head); printWB("\n");
				break;
			case '3': findContactByName(&head);
				break;
			case '4': findContactByNumber(&head);
				break;
			case '5': deleteContactByIndex(&head);
				break;
			case '6': deleteAll(&head); exit(0);
				break;
			default: printf("Unknown command\n\n");
		}
	}
}