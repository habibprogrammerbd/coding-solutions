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
**Runtime:** 0 ms  
**Memory:** 8.2 MB  
**Submitted:** 2026-11-26T08:41:18.428Z  

```cpp
class Solution {
public:
    bool checkValid(vector<vector<int>>& mat) {
       
        int sz = mat[0].size();

        for(int i = 0; i < sz; i++)
        {
            vector<bool> find_one(sz, false);
            vector<bool> find_two(sz, false);
            for(int j = 0; j < sz; j++)
            {
                int val = mat[i][j];
                find_one[val -1] = true;
            }

            for(int j = 0; j < sz; j++)
            {
                int val = mat[j][i];
                find_two[val -1] = true;
            }

            for(int k = 0; k < sz; k++)
            {
                if((find_one[k] == false) || (find_two[k] == false)) return false;
            }
        }  

        return true;  
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/check-if-every-row-and-column-contains-all-numbers/)