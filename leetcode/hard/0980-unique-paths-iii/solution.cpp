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