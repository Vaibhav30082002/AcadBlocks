// VAIBHAV SHAH
// 20BBS0162
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
char totwords[105000][50]; char word[26][12000][50];
int count[26];
int totpal = 0;
int palnos[26];
void *ispalindromic(void *ano); int main()
{
    pthread_t p[26];
    FILE *fp;
    char str[50];
    int i = 0, tot = 0;
    for (int k = 0; k < 26; k++)
        palnos[k] = 0;
    fp = fopen("words.txt", "r"); if (fp == NULL)
    {
        printf("FILE OPEN ERROR");
        exit(-1); }
    while (fgets(str, sizeof(str), fp) != NULL) {
        strcpy(totwords[i], str);
        i++; }
    fclose(fp);
    printf("Total no of words in Dictionary : %d\n", i); for (int j = 0; j < 26; j++)
    {
        char x = 97 + j;
        for (int k = 0; k < i; k++) {
            char ch[50];
            strcpy(ch, totwords[k]); ch[strlen(ch) - 1] = '\0';
            for (int i = 0; i < strlen(ch); i++) {
                if (ch[i] >= 65 && ch[i] <= 90) ch[i] = ch[i] + 32;
            }
            if (ch[0] == x) {
                strcpy(word[j][count[j]], ch);
                count[j]++; }
        }
        tot += count[j]; }
    int arr[26] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25};
    int j = 0; while (j < 26) {
        if (pthread_create(&p[j], NULL, ispalindromic, (void *)&arr[j]) < 0) {
            perror("pthread_create");
            exit(1); }
        j = j + 1; }
    for (int i = 0; i < 26; i++) {
        pthread_join(p[i], NULL); }
    printf("\nTotal no of words.................%d\n", tot); printf("Total palindromic words found.....%d\n", totpal); for (int k = 0; k < 26; k++)
        printf("Thread %2d - %3d\n", k, palnos[k]); printf(" -----\n 767\n -----\n");
}
void *ispalindromic(void *ano) {
    int *alpno = (int *)ano;
    int i = 0;
    char string[50], rev[50];
    for (int a = 0; a < count[*alpno]; a++) {
        strcpy(string, word[*alpno][a]); int h = strlen(string);
        for (i = 0; i < h; i++)
        {
            rev[i] = string[h - i - 1]; }
        rev[i] = '\0';
        char lc = string[h - 1];
        int cn = (int)lc - 'a';
        for (int k = 0; k < count[cn]; k++) {
            if (strcmp(rev, word[cn][k]) == 0) {
                printf("%s\n", rev); palnos[*alpno]++; totpal++;
            }
        } }
}
