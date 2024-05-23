#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "PrintOp.h"

int min(int a, int b, int c) {
    return (a < b ? (a < c ? a : c) : (b < c ? b : c));
}

void print_operations(char* code, char* rule, int** dp, int code_len, int rule_len) {
    int i = code_len;
    int j = rule_len;
    while (i > 0 || j > 0) {
        if (i > 0 && j > 0 && code[i - 1] == rule[j - 1]) {
            i--;
            j--;
        }
        else if (i > 0 && dp[i][j] == dp[i - 1][j] + 1) {
            printf("Delete '%c' at position %d\n", code[i - 1], i - 1);
            i--;
        }
        else if (j > 0 && dp[i][j] == dp[i][j - 1] + 1) {
            printf("Insert '%c' at position %d\n", rule[j - 1], i);
            j--;
        }
        else {
            printf("Substitute '%c' at position %d with '%c'\n", code[i - 1], i - 1, rule[j - 1]);
            i--;
            j--;
        }
    }
}
int levenshtein(char* s1, char* s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int** d = (int**)malloc((len1 + 1) * sizeof(int*));
    for (int i = 0; i <= len1; i++) {
        d[i] = (int*)malloc((len2 + 1) * sizeof(int));
    }

    for (int i = 0; i <= len1; i++) d[i][0] = i;
    for (int j = 0; j <= len2; j++) d[0][j] = j;

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
            d[i][j] = min(d[i - 1][j] + 1, d[i][j - 1] + 1, d[i - 1][j - 1] + cost);
        }
    }

    print_operations(s1, s2, d, len1, len2);

    int result = d[len1][len2];

    for (int i = 0; i <= len1; i++) {
        free(d[i]);
    }
    free(d);

    return result;
}

void generate_random_string(char* str, int length) {
    static const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 0; i < length; i++) {
        int key = rand() % (int)(sizeof(charset) - 1);
        str[i] = charset[key];
    }
    str[length] = '\0';
}