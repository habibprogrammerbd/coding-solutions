# Combination Sum II

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given a collection of candidate numbers (`candidates`) and a target number (`target`), find all unique combinations in `candidates` where the candidate numbers sum to `target`.

Each number in `candidates` may only be used  **once**  in the combination.

 **Note:**  The solution set must not contain duplicate combinations.

 

Original
C++
 **Example 1:** 

```
Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]

```

 **Example 2:** 

```
Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
]

```

 

 **Constraints:** 

- 1 <= candidates.length <= 100
- 1 <= candidates[i] <= 50
- 1 <= target <= 30

## Solution

**Language:** C++  
**Runtime:** 3 ms (beats 30.85%)  
**Memory:** 13.9 MB (beats 78.81%)  
**Submitted:** 2026-11-22T16:32:18.626Z  

```cpp
class Solution {
public:
    void getAllcom(int idx, vector<vector<int>>& ans, vector<int>& curr, int tar, vector<int>& can)
    {
        if (tar == 0)
        {
            ans.push_back(curr);
            return;
        }

        for (int i = idx; i < can.size(); i++)
        {
            if (i > idx && can[i] == can[i - 1]) continue; 
            if (can[i] > tar) break;                      

            curr.push_back(can[i]);
            getAllcom(i + 1, ans, curr, tar - can[i], can); 
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> curr;
        sort(candidates.begin(), candidates.end());
        getAllcom(0, ans, curr, target, candidates);
        return ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/combination-sum-ii/)