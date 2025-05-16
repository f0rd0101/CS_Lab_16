#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_LEN 1000

char **splitWords(char *str, int *wordCount) {
    char **words = malloc(MAX_WORDS * sizeof(char *));
    *wordCount = 0;

    char *start = str;
    while (*start != '\0') {
        while (isspace(*start)) start++;

        if (*start == '\0') break;

        char *end = start;
        while (*end != '\0' && !isspace(*end)) end++;

        int len = end - start;
        words[*wordCount] = malloc((len + 1) * sizeof(char));
        strncpy(words[*wordCount], start, len);
        words[*wordCount][len] = '\0';

        (*wordCount)++;
        start = end;
    }

    return words;
}

int main() {
    char input[MAX_LEN];
    printf("Введи рядок: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';

    int count;
    char **words = splitWords(input, &count);

    printf("Знайдено слів: %d\n", count);
    for (int i = 0; i < count; i++) {
        printf("Слово %d: %s\n", i + 1, words[i]);
        free(words[i]);
    }

    free(words);
    return 0;
}
