#ifndef MYFILEFUNCTIONS_H
#define MYFILEFUNCTIONS_H

#include <stdio.h>

/* Count the number of lines, words and characters in the passed FILE pointer.
   Return 0 on success and -1 on failure. */
int wordCount(FILE* file, int* lines, int* words, int* chars);

/* Search lines containing search_str in a file, and fills the matches array.
   On success returns number of matches (>=0) and sets *matches to an array
   of malloc'd strings (caller must free). Returns -1 on failure. */
int mygrep(FILE* fp, const char* search_str, char*** matches);

#endif /* MYFILEFUNCTIONS_H */
