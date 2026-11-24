# N-Queens II

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

The  **n-queens**  puzzle is the problem of placing `n` queens on an `n x n` chessboard such that no two queens attack each other.

Given an integer `n`, return  *the number of distinct solutions to the  **n-queens puzzle***.

 

Original
C++
 **Example 1:** 

```
Input: n = 4
Output: 2
Explanation: There are two distinct solutions to the 4-queens puzzle as shown.

```

 **Example 2:** 

```
Input: n = 1
Output: 1

```

 

 **Constraints:** 

- 1 <= n <= 9

## Solution

**Language:** C++  
**Runtime:** 3 ms (beats 26.38%)  
**Memory:** 8.4 MB (beats 27.54%)  
**Submitted:** 2026-11-24T14:42:22.033Z  

```cpp
class Solution {
public:
    bool isSafe(vector<string> &bord, int row, int col, int n)
    {
        for(int i = col; i >= 0; i--)
        {
            if(bord[row][i] == 'Q')
                return false;
        }

        for(int i = row; i >= 0; i--)
        {
            if(bord[i][col] == 'Q')
                return false;
        }

        for(int i = row, j = col; i >= 0 && j >= 0; i--,j--)
        {
            if(bord[i][j] == 'Q')
                return false;
        }

        for(int i = row, j = col; i >= 0 && j < n; i--,j++)
        {
            if(bord[i][j] == 'Q')
                return false;
        }

        return true;

    }
    int nQueens(vector<string> &bord, int row, int n)
    {
        if(row == n)
        {
            return 1;
        }
        int count = 0;
        for(int i = 0; i < n; i++)
        {
            if(isSafe(bord, row, i, n))
            {
                bord[row][i] = 'Q';
                count+=nQueens(bord, row+1, n);
                bord[row][i] = '.';
            }
        }
        
        return count;
    }
    int totalNQueens(int n) {
        vector<string> bord(n,string(n,'.'));

        return nQueens(bord, 0, n);
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/n-queens-ii/)