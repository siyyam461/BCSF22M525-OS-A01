#include "../include/mystrfunctions.h"

/* Return length of string (not counting terminating NUL) */
int mystrlen(const char* s) {
    const char *p = s;
    if (!s) return 0;
    while (*p) ++p;
    return (int)(p - s);
}

/* Copy src into dest. Return number of bytes copied (excluding NUL). */
int mystrcpy(char* dest, const char* src) {
    char *d = dest;
    const char *s = src;
    if (!dest || !src) return -1;
    while ((*d++ = *s++)) {}
    return mystrlen(dest);
}

/* Copy at most n bytes from src to dest; ensures NUL termination.
   Returns number of bytes written (excluding NUL). */
int mystrncpy(char* dest, const char* src, int n) {
    int i;
    if (!dest || !src || n <= 0) return 0;
    for (i = 0; i < n - 1 && src[i]; ++i) dest[i] = src[i];
    dest[i] = '\0';
    return i;
}

/* Append src to dest. Returns new length of dest (excluding NUL). */
int mystrcat(char* dest, const char* src) {
    char *d = dest;
    const char *s = src;
    if (!dest || !src) return -1;
    while (*d) ++d;
    while ((*d++ = *s++)) {}
    return mystrlen(dest);
}
