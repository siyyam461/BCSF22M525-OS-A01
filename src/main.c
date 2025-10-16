#include <stdio.h>
#include <stdlib.h>
#include "../include/mystrfunctions.h"
#include "../include/myfilefunctions.h"

int main(void) {
    printf("--- Testing String Functions ---\n");
    char a[256] = "Hello";
    mystrcat(a, ", world!");
    printf("Concatenated: %s (len=%d)\n", a, mystrlen(a));

    char b[32];
    mystrcpy(b, "abc");
    printf("Copied: %s\n", b);
    mystrncpy(b, "longstring", 5);
    printf("Strncpy(5): %s\n", b);

    printf("\n--- Testing File Functions ---\n");
    FILE *f = fopen("/etc/hosts", "r"); /* small system file usually present */
    if (!f) {
        perror("fopen");
        return 1;
    }

    int lines = 0, words = 0, chars = 0;
    if (wordCount(f, &lines, &words, &chars) == 0) {
        printf("/etc/hosts -> lines=%d words=%d chars=%d\n", lines, words, chars);
    } else {
        printf("wordCount failed\n");
    }

    char **matches = NULL;
    int cnt = mygrep(f, "localhost", &matches);
    printf("mygrep for 'localhost' returned %d\n", cnt);
    for (int i = 0; i < cnt; ++i) {
        printf("match[%d]: %s", i, matches[i]);
        free(matches[i]);
    }
    free(matches);
    fclose(f);
    return 0;
}
