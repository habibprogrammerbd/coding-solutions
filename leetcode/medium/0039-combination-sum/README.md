# Combination Sum

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given an array of  **distinct**  integers `candidates` and a target integer `target`, return  *a list of all  **unique combinations**  of* `candidates` *where the chosen numbers sum to* `target` *.*  You may return the combinations in  **any order**.

The  **same**  number may be chosen from `candidates` an  **unlimited number of times**. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

The test cases are generated such that the number of unique combinations that sum up to `target` is less than `150` combinations for the given input.

 

Original
C++
 **Example 1:** 

```
Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.

```

 **Example 2:** 

```
Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]

```

 **Example 3:** 

```
Input: candidates = [2], target = 1
Output: []

```

 

 **Constraints:** 

- 1 <= candidates.length <= 30
- 2 <= candidates[i] <= 40
- All elements of candidates are distinct.
- 1 <= target <= 40

## Solution

**Language:** C++  
**Runtime:** 17 ms (beats 14.73%)  
**Memory:** 18.9 MB (beats 14.94%)  
**Submitted:** 2026-11-19T16:08:07.480Z  

```cpp
class Solution {
public:
    set<vector<int>> st;
    void getAllcom(int idx, vector<vector<int>>& ans, vector<int>& curr , int tar, vector<int>& can)
    {
        if(can.size() == idx || tar < 0)
        {
            return;
        }

        if(tar == 0)
        {
            if(st.find(curr) == st.end())
            {
                ans.push_back(curr);
                st.insert(curr);
            }
        }

        curr.push_back(can[idx]);

        getAllcom(idx +1, ans, curr, tar - can[idx], can);
        getAllcom(idx, ans, curr, tar - can[idx], can);

        curr.pop_back();
        getAllcom(idx +1, ans, curr, tar, can);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;

        getAllcom(0, ans, curr, target, candidates);

        return ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/combination-sum/)