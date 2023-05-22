#include <stdlib.h>
#include <unistd.h>

#ifndef SIZE
# define SIZE 5
#endif

void create(int*** arr) {
    (*arr) = (int**)malloc(sizeof(int*) * SIZE);
    for(int i = 0; i < SIZE; ++i) {
        (*arr)[i] = (int*)malloc(sizeof(int) * SIZE);
    }
}

void delete(int*** arr) {
    for(int i = 0; i < SIZE; ++i) {
        free((*arr)[i]);
    } 
    free((*arr));
}

void fill(int*** arr) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (j >= SIZE - 1 - i) (*arr)[i][j] = 0;
            else (*arr)[i][j] = 1;
        }
    }
}

void print(int*** arr) {
    for(int i = 0; i < SIZE; ++i) {
        for(int j = 0; j < SIZE; ++j) {
            if ((*arr)[i][j] == 1) write(1, "1", 2);
            else write(1, "0", 2);
        }
        write(1, "\n", 1);
    }
}

int main(void) {
    int** arr;
    create(&arr);
    fill(&arr);
    print(&arr);
    delete(&arr);
}