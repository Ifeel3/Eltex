#include <unistd.h>
#include "list.h"

int main(void) {
    list_t* lst = createList("LolKek", "Cheburek", 528488);
    addList(lst, createList("Hello", "world", 123456));
    addList(lst, createList("Onotole", "Popyachsa", 987654));
    list_t* result = findByIndex(lst, 3);
    (void) result;
    deleteAllLists(lst);
}