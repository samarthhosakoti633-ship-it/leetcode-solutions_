#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) return "";
    
    // Find the length of the first string to set the upper bound
    int minLen = strlen(strs[0]);
    
    // Vertical scanning character by character
    for (int i = 0; i < minLen; i++) {
        char c = strs[0][i];
        for (int j = 1; j < strsSize; j++) {
            // If we reach the end of any string or a character mismatch occurs
            if (i >= strlen(strs[j]) || strs[j][i] != c) {
                // Allocate memory for the common prefix found so far
                char* result = (char*)malloc((i + 1) * sizeof(char));
                strncpy(result, strs[0], i);
                result[i] = '\0';
                return result;
            }
        }
    }
    
    // If the entire first string is a common prefix
    char* result = (char*)malloc((minLen + 1) * sizeof(char));
    strcpy(result, strs[0]);
    return result;
}