#include <stdio.h>
#include <stdlib.h>

#ifndef SIZE
# define SIZE 5
#endif

void print(int* arr) {
    for (int i = 0; i < SIZE; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void fill(int* arr) {
    for (int i = 0; i < SIZE; ++i) {
        arr[i] = i + 1;
    }
}

void changeOrder(int* arr) {
    for (int i = 0; i < SIZE / 2; ++i) {
        arr[SIZE - i - 1] += arr[i];
        arr[i] = arr[SIZE - i - 1] - arr[i];
        arr[SIZE - i - 1] -= arr[i];
    }
}

int main(void) {
    int arr[SIZE];
    fill(arr);
    print(arr);
    changeOrder(arr);
    print(arr);
}