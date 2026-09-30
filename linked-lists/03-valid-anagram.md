# 06. Valid Parentheses

## Problem Description
Given a string `s` containing just the characters `'('`, `')'`, `'{'`, `'}'`, `'['` and `']'`, determine if the input string is valid.

An input string is valid if:
1. Open brackets must be closed by the same type of brackets.
2. Open brackets must be closed in the correct order.
3. Every close bracket has a corresponding open bracket of the same type.

### Examples

**Example 1:**
* **Input:** `s = "()"`
* **Output:** `true`

**Example 2:**
* **Input:** `s = "()[]{}"`
* **Output:** `true`

**Example 3:**
* **Input:** `s = "(]"`
* **Output:** `false`

### Constraints
* $1 \le s.\text{length} \le 10^4$
* `s` consists of parentheses only `'()[]{}'`.

---

## Approach: Stack Data Structure

1. **Length Check:** If the length of the string is odd, it can never have fully matched pairs, so return `false` immediately.
2. **Stack Traversal:** Iterate through the string character by character:
   * If the character is an opening bracket (`(`, `{`, `[`), push it onto the stack.
   * If it is a closing bracket, check if the stack is empty (meaning no matching open bracket exists). If not empty, pop the top element and verify that it matches the corresponding opening bracket type.
3. **Final Validation:** After processing all characters, check if the stack is completely empty. If it is, return `true`; otherwise, return `false`.

---

## C Implementation

```c
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool isValid(char* s) {
    int len = strlen(s);
    // An odd length string can never have valid matching pairs
    if (len % 2 != 0) return false;

    // Allocate stack memory dynamically based on string length
    char* stack = (char*)malloc(len * sizeof(char));
    int top = -1;

    for (int i = 0; i < len; i++) {
        char c = s[i];
        
        // If it's an opening bracket, push it to the stack
        if (c == '(' || c == '{' || c == '[') {
            stack[++top] = c;
        } else {
            // If it's a closing bracket but stack is empty, it's invalid
            if (top == -1) {
                free(stack);
                return false;
            }
            
            // Pop the top element and check if it matches
            char open = stack[top--];
            if ((c == ')' && open != '(') ||
                (c == '}' && open != '{') ||
                (c == ']' && open != '[')) {
                free(stack);
                return false;
            }
        }
    }

    // If the stack is empty, all brackets matched successfully
    bool result = (top == -1);
    free(stack);
    return result;
}