#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "PrintOp.h"
#define DATASETS 10
#define MAX_LENGTH 100






int main() {
    srand(time(NULL));

    // Define an array with 10 datasets
    char datasets[DATASETS][MAX_LENGTH + 1];
    char target[] = "func(myFunction)";
    for (int i = 0; i < DATASETS; i++) {
        int length = (rand() % (MAX_LENGTH - 1)) + 1;
        generate_random_string(datasets[i], length);
    }
    float a = 0;
    // Test Levenshtein distance algorithm and measure execution time
    for (int i = 0, j=1; i < DATASETS; i++) {
        clock_t start = clock();
        int distance = levenshtein(datasets[i], target);
        clock_t end = clock();
        double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("%d Input: %s\n", j, datasets[i]);
        printf("Minimum number of operations: %d\n", distance);
        printf("Execution time: %.6f seconds\n", time_taken);
        printf("\n");
        j++;
        a += time_taken;
    }

    printf(" ukuono sekunde %f", a);
    return 0;
}


