# 08. Move Zeroes

## Problem Description
Given an integer array `nums`, move all `0`'s to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.

### Examples

**Example 1:**
* **Input:** `nums = [0,1,0,3,12]`
* **Output:** `[1,3,12,0,0]`

**Example 2:**
* **Input:** `nums = [0]`
* **Output:** `[0]`

### Constraints
* $1 \le \text{nums.length} \le 10^4$
* $-2^{31} \le \text{nums}[i] \le 2^{31} - 1$

---

## Approach: Two-Pointers / Index Tracking

1. **Initialize Tracking Pointer:** Set `lastNonZeroFoundAt` to `0`. This pointer tracks where the next non-zero element should be placed.
2. **Iterate & Swap:** Traverse the array using index `i`:
   * If `nums[i] != 0`, swap the element at `nums[i]` with the element at `nums[lastNonZeroFoundAt]`.
   * Increment `lastNonZeroFoundAt` after each swap.
3. **Result:** This efficiently shifts all non-zero elements to the front while preserving their relative order and pushes all zeros to the end in-place.

---

## C Implementation

```c
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