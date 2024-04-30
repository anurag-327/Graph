class Solution
{
public:
        int orangesRotting(vector<vector<int>> &grid)
        {
                if (grid.empty())
                        return 0;
                int n = grid.size();
                int m = grid[0].size();
                queue<pair<int, int>> q;
                int tot = 0;
                for (int i = 0; i < n; i++)
                {
                        for (int j = 0; j < m; j++)
                        {
                                if (grid[i][j] == 2)
                                        q.push({i, j});
                                if (grid[i][j] != 0)
                                        tot++;
                        }
                }
                int cnt = 0;
                int k;
                int days = 0;
                int delRow[4] = {-1, 1, 0, 0};
                int delCol[4] = {0, 0, 1, -1};
                while (!q.empty())
                {
                        k = q.size();
                        cnt += k;
                        while (k--)
                        {
                                int row = q.front().first;
                                int col = q.front().second;
                                q.pop();
                                for (int i = 0; i < 4; i++)
                                {
                                        int rown = row + delRow[i];
                                        int coln = col + delCol[i];
                                        if (rown >= 0 && rown < n && coln >= 0 && coln < m && grid[rown][coln] == 1)
                                        {
                                                grid[rown][coln] = 2;
                                                q.push({rown, coln});
                                        }
                                }
                        }
                        if (!q.empty())
                                days++;
                }
                return tot == cnt ? days : -1;
        }
};