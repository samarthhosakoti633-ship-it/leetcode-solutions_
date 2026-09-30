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