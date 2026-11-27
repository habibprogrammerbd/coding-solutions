# Unique Paths III

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

You are given an `m x n` integer array `grid` where `grid[i][j]` could be:

- 1 representing the starting square. There is exactly one starting square.
- 2 representing the ending square. There is exactly one ending square.
- 0 representing empty squares we can walk over.
- -1 representing obstacles that we cannot walk over.

Return  *the number of 4-directional walks from the starting square to the ending square, that walk over every non-obstacle square exactly once*.

 

Original
C++
 **Example 1:** 

```
Input: grid = [[1,0,0,0],[0,0,0,0],[0,0,2,-1]]
Output: 2
Explanation: We have the following two paths: 
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)

```

 **Example 2:** 

```
Input: grid = [[1,0,0,0],[0,0,0,0],[0,0,0,2]]
Output: 4
Explanation: We have the following four paths: 
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2),(2,3)
2. (0,0),(0,1),(1,1),(1,0),(2,0),(2,1),(2,2),(1,2),(0,2),(0,3),(1,3),(2,3)
3. (0,0),(1,0),(2,0),(2,1),(2,2),(1,2),(1,1),(0,1),(0,2),(0,3),(1,3),(2,3)
4. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2),(2,3)

```

 **Example 3:** 

```
Input: grid = [[0,1],[2,0]]
Output: 0
Explanation: There is no path that walks over every empty square exactly once.
Note that the starting and ending square can be anywhere in the grid.

```

 

 **Constraints:** 

- m == grid.length
- n == grid[i].length
- 1 <= m, n <= 20
- 1 <= m * n <= 20
- -1 <= grid[i][j] <= 2
- There is exactly one starting cell and one ending cell.

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 9.1 MB (beats 95.99%)  
**Submitted:** 2026-11-27T05:05:02.474Z  

```cpp
class Solution {
public:
    int mustVisit = 0, row_sz = 0, col_sz = 0, result = 0;

    void backtrack(vector<vector<int>>& grid, int row, int col, int count)
    {
        if(row < 0 || row >= row_sz || col < 0 || col >= col_sz || grid[row][col] == -1)
        {
            return;
        }

        if(grid[row][col] == 2)
        {
            if(mustVisit == count)
            {
                result++;
                return;
            }
        }

        int temp = grid[row][col];
        grid[row][col] = -1;

        backtrack(grid, row, col +1, count +1);
        backtrack(grid, row +1, col, count +1);
        backtrack(grid, row , col -1, count +1);
        backtrack(grid, row -1, col, count +1);

        grid[row][col] = temp;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        int st_row = 0, st_col = 0;
        row_sz = grid.size(), col_sz = grid[0].size();

        for(int i = 0; i < row_sz; i++)
        {
            for(int j = 0; j < col_sz; j++)
            {
                if(grid[i][j] == 0)
                {
                    mustVisit++;
                }
                else if(grid[i][j] == 1)
                {
                    st_row = i;
                    st_col = j;
                    mustVisit++;
                }
            }
        }

        backtrack(grid, st_row, st_col, 0);

        return result;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/unique-paths-iii/)