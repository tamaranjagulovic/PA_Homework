#pragma once



int min(int a, int b, int c);
void print_operations(char* code, char* rule, int** dp, int code_len, int rule_len);
int levenshtein(char* s1, char* s2);
void generate_random_string(char* str, int length);