# 02. Reverse String

## Problem Description
Write a function that reverses a string. The input string is given as an array of characters `s`.

You must do this by modifying the input array **in-place** with $O(1)$ extra memory.

### Examples

**Example 1:**
* **Input:** `s = ["h","e","l","l","o"]`
* **Output:** `["o","l","l","e","h"]`

**Example 2:**
* **Input:** `s = ["H","a","n","n","a","h"]`
* **Output:** `["h","a","n","n","a","H"]`

### Constraints
* $1 \le s.\text{length} \le 10^5$
* $s[i]$ is a printable ASCII character.

---

## Approach: Two-Pointer Technique

1. Initialize two pointers: `left` at the start (`0`) and `right` at the end (`sSize - 1`) of the array.
2. Swap the characters at `s[left]` and `s[right]`.
3. Move `left` forward and `right` backward (`left++`, `right--`).
4. Repeat until the pointers meet in the middle (`left >= right`).

---

## C Implementation

```c
void reverseString(char* s, int sSize) {
    int left = 0;
    int right = sSize - 1;
    
    while (left < right) {
        // Swap characters at left and right pointers
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        
        // Move pointers toward the center
        left++;
        right--;
    }
}