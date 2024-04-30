class Solution
{
public:
        // Function to find distance of nearest 1 in the grid for each cell.
        vector<vector<int>> nearest(vector<vector<int>> grid)
        {
                // Code here
                int n = grid.size();
                int m = grid[0].size();
                vector<vector<bool>> vis(n, vector<bool>(m, false));
                vector<vector<int>> ans(n, vector<int>(m, 0));
                queue<pair<int, pair<int, int>>> q;
                //{dis,{i,j}}
                for (int i = 0; i < n; i++)
                {
                        for (int j = 0; j < m; j++)
                        {
                                if (grid[i][j] == 1)
                                {
                                        q.push({0, {i, j}});
                                        vis[i][j] = true;
                                }
                                else
                                        vis[i][j] = false;
                        }
                }
                int delRow[4] = {-1, 0, 0, 1};
                int delCol[4] = {0, -1, 1, 0};
                while (!q.empty())
                {
                        int dis = q.front().first;
                        int row = q.front().second.first;
                        int col = q.front().second.second;
                        q.pop();
                        ans[row][col] = dis;
                        for (int i = 0; i < 4; i++)
                        {
                                int rown = row + delRow[i];
                                int coln = col + delCol[i];
                                if (rown >= 0 && rown < n && coln >= 0 && coln < m && vis[rown][coln] == false)
                                {
                                        vis[rown][coln] = true;
                                        q.push({dis + 1, {rown, coln}});
                                }
                        }
                }
                return ans;
        }
};