# 04. Best Time to Buy and Sell Stock

## Problem Description
You are given an array `prices` where `prices[i]` is the price of a given stock on the $i$-th day.

You want to maximize your profit by choosing a **single day** to buy one stock and choosing a **different day in the future** to sell that stock.

Return *the maximum profit you can achieve from this transaction*. If you cannot achieve any profit, return `0`.

### Examples

**Example 1:**
* **Input:** `prices = [7,1,5,3,6,4]`
* **Output:** `5`
* **Explanation:** Buy on day 2 (`price = 1`) and sell on day 5 (`price = 6`), profit = $6 - 1 = 5$. Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

**Example 2:**
* **Input:** `prices = [7,6,4,Here is the markdown file content for the **Best Time to Buy and Sell Stock** problem and its C solution:

```markdown
# 04. Best Time to Buy and Sell Stock

## Problem Description
You are given an array `prices` where `prices[i]` is the price of a given stock on the $i$-th day.

You want to maximize your profit by choosing a **single day** to buy one stock and choosing a **different day in the future** to sell that stock.

Return *the maximum profit you can achieve from this transaction*. If you cannot achieve any profit, return `0`.

### Examples

**Example 1:**
* **Input:** `prices = [7,1,5,3,6,4]`
* **Output:** `5`
* **Explanation:** Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = $6 - 1 = 5$.

**Example 2:**
* **Input:** `prices = [7,6,4,3,1]`
* **Output:** `0`
* **Explanation:** In this case, no transactions are done and the maximum profit is 0.

### Constraints
* $1 \le \text{prices.length} \le 10^5$
* $0 \le \text{prices}[i] \le 10^4$

---

## Approach: One-Pass Greedy

1. Initialize `minPrice` to the first day's price (`prices[0]`) and `maxProfit` to `0`.
2. Iterate through the array starting from the second day:
   * If the current price is lower than `minPrice`, update `minPrice` to this new lower value.
   * Otherwise, calculate the potential profit (`prices[i] - minPrice`) and update `maxProfit` if this profit is greater than the current maximum.
3. Return `maxProfit`.

---

## C Implementation

```c
int maxProfit(int* prices, int pricesSize) {
    if (pricesSize <= 1) return 0;
    
    int minPrice = prices[0];
    int maxProfit = 0;
    
    for (int i = 1; i < pricesSize; i++) {
        if (prices[i] < minPrice) {
            minPrice = prices[i];
        } else if (prices[i] - minPrice > maxProfit) {
            maxProfit = prices[i] - minPrice;
        }
    }
    
    return maxProfit;
}