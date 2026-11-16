# Split Array Largest Sum

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

Given an integer array `nums` and an integer `k`, split `nums` into `k` non-empty subarrays such that the largest sum of any subarray is  **minimized**.

Return  *the minimized largest sum of the split*.

A  **subarray**  is a contiguous part of the array.

 

Original
C++
 **Example 1:** 

```
Input: nums = [7,2,5,10,8], k = 2
Output: 18
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8], where the largest sum among the two subarrays is only 18.

```

 **Example 2:** 

```
Input: nums = [1,2,3,4,5], k = 2
Output: 9
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [1,2,3] and [4,5], where the largest sum among the two subarrays is only 9.

```

 

 **Constraints:** 

- 1 <= nums.length <= 1000
- 0 <= nums[i] <= 106
- 1 <= k <= min(50, nums.length)

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 10.5 MB (beats 30.53%)  
**Submitted:** 2026-11-16T13:08:31.565Z  

```cpp
class Solution {
public:
    bool isValid(vector<int>& num, int mid, int k)
    {
        int std = 1, sum = 0;
        for(int i = 0; i < num.size(); i++)
        {
            if(num[i] > mid) return false;

            if(sum + num[i] <= mid)
            {
                sum+=num[i];
            }
            else
            {
                std++;
                sum = num[i];
            }
        }

        return std <= k;
    }
    int splitArray(vector<int>& nums, int k) {
        int st = *max_element(nums.begin(),nums.end()), end = accumulate(nums.begin(),nums.end(),0), ans = end;

        while(st <= end)
        {
            int mid = st + (end - st) / 2;

            if(isValid(nums, mid, k))
            {
                ans = mid;
                end = mid -1;
            }
            else st = mid +1;
        }

        return ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/split-array-largest-sum/)