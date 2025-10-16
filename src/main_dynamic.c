#include <stdio.h>
#include <stdlib.h>
#include "../include/mystrfunctions.h"
#include "../include/myfilefunctions.h"

int main(void) {
    printf("--- client_dynamic: Testing String Functions ---\n");
    char a[256] = "Dynamic";
    mystrcat(a, " library");
    printf("Concatenated: %s (len=%d)\n", a, mystrlen(a));

    char b[32];
    mystrcpy(b, "xyz");
    printf("Copied: %s\n", b);

    printf("\n--- client_dynamic: Testing File Functions ---\n");
    FILE *f = fopen("/etc/hosts", "r");
    if (!f) { perror("fopen"); return 1; }
    int lines=0, words=0, chars=0;
    if (wordCount(f, &lines, &words, &chars) == 0) {
        printf("/etc/hosts -> lines=%d words=%d chars=%d\n", lines, words, chars);
    } else {
        printf("wordCount failed\n");
    }

    char **matches=NULL;
    int cnt = mygrep(f, "localhost", &matches);
    printf("mygrep for 'localhost' returned %d\n", cnt);
    for (int i=0;i<cnt;i++){
        printf("match[%d]: %s", i, matches[i]);
        free(matches[i]);
    }
    free(matches);
    fclose(f);
    return 0;
}
