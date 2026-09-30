#include <stdio.h>

void moveZeroes(int* nums, int numsSize) {
    int lastNonZeroFoundAt = 0;
    
    // Traverse through the array. If an element is non-zero,
    // swap it with the element at lastNonZeroFoundAt.
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != 0) {
            int temp = nums[lastNonZeroFoundAt];
            nums[lastNonZeroFoundAt] = nums[i];
            nums[i] = temp;
            lastNonZeroFoundAt++;
        }
    }
}