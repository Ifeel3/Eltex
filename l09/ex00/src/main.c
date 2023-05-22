#include <stdio.h>

#define N 3
#define M 5

int main(void) {
    int k = 0;
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j, ++k) {
            printf("%d ", k);
        }
        printf("\n");
    }
}