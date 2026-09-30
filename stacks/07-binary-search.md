# 07. Binary Search

## Problem Description
Given an array of integers `nums` which is sorted in ascending order, and an integer `target`, write a function to search `target` in `nums`. If `target` exists, then return its index. Otherwise, return `-1`.

You must write an algorithm with $O(\log n)$ runtime complexity.

### Examples

**Example 1:**
* **Input:** `nums = [-1,0,3,5,9,12]`, `target = 9`
* **Output:** `4`
* **Explanation:** `9` exists in `nums` and its index is `4`.

**Example 2:**
* **Input:** `nums = [-1,0,3,5,9,12]`, `target = 2`
* **Output:** `-1`
* **Explanation:** `2` does not exist in `nums` so return `-1`.

### Constraints
* $1 \le \text{nums.length} \le 10^4$
* $-10^4 < \text{nums}[i], \text{target} < 10^4$
* All the integers in `nums` are unique.
* `nums` is sorted in ascending order.

---

## Approach: Binary Search

1. **Initialize Pointers:** Set `left` to `0` and `right` to `numsSize - 1`.
2. **Iterate:** While `left <= right`:
   * Calculate the middle index using `mid = left + (right - left) / 2` to prevent integer overflow.
   * Compare `nums[mid]` with the `target`:
     * If `nums[mid] == target`, return `mid`.
     * If `nums[mid] < target`, the target is in the right half, so update `left = mid + 1`.
     * If `nums[mid] > target`, the target is in the left half, so update `right = mid - 1`.
3. **Not Found:** If the loop terminates without finding the target, return `-1`.

---

## C Implementation

```c
#include <stdio.h>

int search(int* nums, int numsSize, int target) {
    int left = 0;
    int right = numsSize - 1;
    
    while (left <= right) {
        // Prevent potential integer overflow
        int mid = left + (right - left) / 2;
        
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return -1; // Target not found
}