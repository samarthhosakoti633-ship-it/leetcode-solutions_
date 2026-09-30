# 03. Valid Anagram

## Problem Description
Given two strings `s` and `t`, return `true` if `t` is an anagram of `s`, and `false` otherwise.

### Examples

**Example 1:**
* **Input:** `s = "anagram", t = "nagaram"`
* **Output:** `true`

**Example 2:**
* **Input:** `s = "rat", t = "car"`
* **Output:** `false`

### Constraints
* $1 \le s.\text{length}, t.\text{length} \le 5 \times 10^4$
* `s` and `t` consist of lowercase English letters.

---

## Approach: Frequency Counter (Array)

Since the characters are restricted to lowercase English letters, we can use a fixed-size frequency array of size 26.
1. First, check if the lengths of both strings are equal. If not, they cannot be anagrams.
2. Iterate through both strings simultaneously: increment the count for characters in `s` and decrement for characters in `t`.
3. Finally, verify if all counts in the array are zero.

---

## C Implementation

```c
#include <stdbool.h>
#include <string.h>

bool isAnagram(char* s, char* t) {
    // If lengths differ, they cannot be anagrams
    if (strlen(s) != strlen(t)) {
        return false;
    }
    
    int count[26] = {0};
    
    // Increment for characters in s, decrement for characters in t
    for (int i = 0; s[i] != '\0'; i++) {
        count[s[i] - 'a']++;
        count[t[i] - 'a']--;
    }
    
    // Check if all counts are zero
    for (int i = 0; i < 26; i++) {
        if (count[i] != 0) {
            return false;
        }
    }
    
    return true;
}