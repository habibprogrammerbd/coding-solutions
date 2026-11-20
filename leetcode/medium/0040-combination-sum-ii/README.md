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
**Runtime:** 0 ms  
**Memory:** 8.5 MB  
**Submitted:** 2026-11-20T15:24:54.910Z  

```cpp
class Solution {
public:
    set<vector<int>> st;
    void getAllcom(int idx, vector<vector<int>>& ans, vector<int>& curr , int tar, vector<int>& can)
    {
        if(can.size() == idx || tar < 0)
        {
            if(tar == 0)
            {
                sort(curr.begin(),curr.end());

                if(st.find(curr) == st.end())
                {
                    ans.push_back(curr);
                    st.insert(curr);
                }
            }
            return;
        }

        if(tar == 0)
        {
            sort(curr.begin(),curr.end());

            if(st.find(curr) == st.end())
            {
                ans.push_back(curr);
                st.insert(curr);
            }
        }

        curr.push_back(can[idx]);

        getAllcom(idx +1, ans, curr, tar - can[idx], can);

        curr.pop_back();
        
        getAllcom(idx +1, ans, curr, tar, can);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        // sort(candidates.begin(), candidates.end());
        getAllcom(0, ans, curr, target, candidates);

        return ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/combination-sum-ii/)