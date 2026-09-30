# 05. Longest Common Prefix

## Problem Description
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string `""`.

### Examples

**Example 1:**
* **Input:** `strs = ["flower","flow","flight"]`
* **Output:** `"fl"`

**Example 2:**
* **Input:** `strs = ["dog","racecar","car"]`
* **Output:** `""`
* **Explanation:** There is no common prefix among the input strings.

### Constraints
* $1 \le \text{strs.length} \le 200$
* $0 \le \text{strs}[i].\text{length} \le 200$
* `strs[i]` consists of only lowercase English letters if it is non-empty.

---

## Approach: Vertical Scanning

1. Check if the array is empty. If so, return `""`.
2. Iterate through the characters of the first string column by column (index `i` from `0` to `minLen - 1`).
3. For each character, compare it against the character at the same index in all other strings.
4. If a mismatch is found or if we reach the end of any string, slice and return the prefix found up to that point.
5. If the loop completes without mismatches, the entire first string is the longest common prefix.

---

## C Implementation

```c
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