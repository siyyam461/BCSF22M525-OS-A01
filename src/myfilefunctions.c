#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include "../include/myfilefunctions.h"

/* portable strdup replacement */
static char *my_strdup(const char *s) {
    if (!s) return NULL;
    size_t n = strlen(s);
    char *p = malloc(n + 1);
    if (!p) return NULL;
    memcpy(p, s, n + 1);
    return p;
}

/* Count lines, words, chars in file */
int wordCount(FILE* file, int* lines, int* words, int* chars) {
    if (!file || !lines || !words || !chars) return -1;
    char buf[4096];
    int l = 0, w = 0, c = 0;
    int inword = 0;

    rewind(file);
    while (fgets(buf, sizeof(buf), file)) {
        l++;
        for (size_t i = 0; buf[i] != '\0'; ++i) {
            char ch = buf[i];
            c++;
            if (ch == ' ' || ch == '\t' || ch == '\n') {
                if (inword) { w++; inword = 0; }
            } else {
                inword = 1;
            }
        }
    }
    if (inword) w++;

    *lines = l;
    *words = w;
    *chars = c;
    return 0;
}

/* Search for lines containing search_str. Uses fgets (portable).
   Allocates array of strings in *matches. Caller must free each string and free(*matches).
   Returns number of matches or -1 on error. */
int mygrep(FILE* fp, const char* search_str, char*** matches) {
    if (!fp || !search_str || !matches) return -1;

    char line[4096];
    int capacity = 8;
    int count = 0;
    char **arr = malloc(capacity * sizeof(char*));
    if (!arr) return -1;

    rewind(fp);
    while (fgets(line, sizeof(line), fp) != NULL) {
        if (strstr(line, search_str) != NULL) {
            if (count >= capacity) {
                capacity *= 2;
                char **tmp = realloc(arr, capacity * sizeof(char*));
                if (!tmp) {
                    for (int i = 0; i < count; ++i) free(arr[i]);
                    free(arr);
                    return -1;
                }
                arr = tmp;
            }
            arr[count] = my_strdup(line);
            if (!arr[count]) {
                for (int i = 0; i < count; ++i) free(arr[i]);
                free(arr);
                return -1;
            }
            count++;
        }
    }

    *matches = arr;
    return count;
}
