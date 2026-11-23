# N-Queens

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

The  **n-queens**  puzzle is the problem of placing `n` queens on an `n x n` chessboard such that no two queens attack each other.

Given an integer `n`, return  *all distinct solutions to the  **n-queens puzzle***. You may return the answer in  **any order**.

Each solution contains a distinct board configuration of the n-queens' placement, where `'Q'` and `'.'` both indicate a queen and an empty space, respectively.

 

Original
C++
 **Example 1:** 

```
Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above

```

 **Example 2:** 

```
Input: n = 1
Output: [["Q"]]

```

 

 **Constraints:** 

- 1 <= n <= 9

## Solution

**Language:** C++  
**Runtime:** 2 ms (beats 75.00%)  
**Memory:** 10.2 MB (beats 75.03%)  
**Submitted:** 2026-11-23T11:28:01.307Z  

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
    void nQueens(vector<string> &bord, vector<vector<string>> &ans, int row, int n)
    {
        if(row == n)
        {
            ans.push_back(bord);
            return;
        }

        for(int i = 0; i < n; i++)
        {
            if(isSafe(bord, row, i, n))
            {
                bord[row][i] = 'Q';
                nQueens(bord, ans, row+1, n);
                bord[row][i] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> bord(n,string(n, '.'));
        vector<vector<string>> ans;
        nQueens(bord, ans, 0, n);
        
        return ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/n-queens/)