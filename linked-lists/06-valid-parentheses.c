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