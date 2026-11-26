# Check if Every Row and Column Contains All Numbers

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

An `n x n` matrix is  **valid**  if every row and every column contains  **all**  the integers from `1` to `n` (**inclusive**).

Given an `n x n` integer matrix `matrix`, return `true`  *if the matrix is  **valid**.*  Otherwise, return `false`.

 

 **Example 1:** 

```
Input: matrix = [[1,2,3],[3,1,2],[2,3,1]]
 matrix = [[1,2,3],[3,1,2],[2,3,1]]
Output: true
Explanation: In this case, n = 3, and every row and column contains the numbers 1, 2, and 3.
Hence, we return true.

```

 **Example 2:** 

```
Input: matrix = [[1,1,1],[1,2,3],[1,2,3]]
 matrix = [[1,1,1],[1,2,3],[1,2,3]]
Output: false
Explanation: In this case, n = 3, but the first row and the first column do not contain the numbers 2 or 3.
Hence, we return false.

```

 

 **Constraints:** 

- n == matrix.length == matrix[i].length
- 1 <= n <= 100
- 1 <= matrix[i][j] <= n

## Solution

**Language:** C++  
**Runtime:** 180 ms (beats 17.07%)  
**Memory:** 95.7 MB (beats 20.13%)  
**Submitted:** 2026-11-26T08:23:36.363Z  

```cpp
class Solution {
public:
    bool checkValid(vector<vector<int>>& mat) {
        unordered_map<int, int> mp;
        int x = mat[0].size();
        for(int i = 1; i <= x; i++)
            mp[i]++;

        for(int i = 0; i < x; i++)
        {
            unordered_map<int,int> mp1;
            unordered_map<int,int> mp2;
            for(int j = 0; j < x; j++)
            {
                int val = mat[i][j];
                mp1[val]++;
            }

            for(int j = 0; j < x; j++)
            {
                int val = mat[j][i];
                mp2[val]++;
            }

            if((mp != mp1) || (mp != mp2))
            {
                return false;
            }

            mp1.clear();
            mp2.clear();
        }  

        return true;  
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/check-if-every-row-and-column-contains-all-numbers/)