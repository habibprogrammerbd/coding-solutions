# Capacity To Ship Packages Within D Days

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

A conveyor belt has packages that must be shipped from one port to another within `days` days.

The `ith` package on the conveyor belt has a weight of `weights[i]`. Each day, we load the ship with packages on the conveyor belt (in the order given by `weights`). We may not load more weight than the maximum weight capacity of the ship.

Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within `days` days.

 

Original
C++
 **Example 1:** 

```
Input: weights = [1,2,3,4,5,6,7,8,9,10], days = 5
Output: 15
Explanation: A ship capacity of 15 is the minimum to ship all the packages in 5 days like this:
1st day: 1, 2, 3, 4, 5
2nd day: 6, 7
3rd day: 8
4th day: 9
5th day: 10

Note that the cargo must be shipped in the order given, so using a ship of capacity 14 and splitting the packages into parts like (2, 3, 4, 5), (1, 6, 7), (8), (9), (10) is not allowed.

```

 **Example 2:** 

```
Input: weights = [3,2,2,4,1,4], days = 3
Output: 6
Explanation: A ship capacity of 6 is the minimum to ship all the packages in 3 days like this:
1st day: 3, 2
2nd day: 2, 4
3rd day: 1, 4

```

 **Example 3:** 

```
Input: weights = [1,2,3,1,1], days = 4
Output: 3
Explanation:
1st day: 1
2nd day: 2
3rd day: 3
4th day: 1, 1

```

 

 **Constraints:** 

- 1 <= days <= weights.length <= 5 * 104
- 1 <= weights[i] <= 500

## Solution

**Language:** C++  
**Runtime:** 14 ms (beats 28.68%)  
**Memory:** 34.9 MB (beats 72.52%)  
**Submitted:** 2026-11-18T07:37:25.569Z  

```cpp
class Solution {
public:
    int isValid(vector<int>& we, int mid)
    {
        int dy = 1, sum = 0;
        for(int i = 0; i < we.size(); i++)
        {
            if(sum + we[i] <= mid)
            {
                sum+=we[i];
            }
            else
            {
                dy++;
                sum = we[i];
            }
        }

        return dy;
    }
    int shipWithinDays(vector<int>& we, int day) {
        int st = *max_element(we.begin(),we.end()), end = accumulate(we.begin(),we.end(), 0), ans = 0;

        while(st <= end)
        {
            int mid = (st+end)/2;

            if(isValid(we, mid) <= day)
            {
                ans = mid;
                end = mid-1;
            }
            else st = mid +1;
        }

        return ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/)