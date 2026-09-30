## Problem: Two Sum (Easy)
### Approach

I used a brute-force approach with two nested loops. The outer loop selects the first element, and the inner loop searches for another element that adds up to the target. When the pair is found, I return their indices.

### Complexity

* Time: O(n²)
* Space: O(1) auxiliary space (excluding the returned array)

### Notes

The inner loop starts at `i + 1` so that the same element is not used twice. I also tested duplicate values, such as `[3, 3]`, with a target of `6`.
