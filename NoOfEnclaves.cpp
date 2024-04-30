class Solution
{
public:
        int numEnclaves(vector<vector<int>> &board)
        {
                int n = board.size();
                int m = board[0].size();
                queue<pair<int, int>> q;
                vector<vector<bool>> vis(n, vector<bool>(m, false));
                for (int i = 0; i < n; i++)
                {
                        for (int j = 0; j < m; j++)
                        {
                                if (i == 0 || j == 0 || i == n - 1 || j == m - 1)
                                {
                                        if (board[i][j] == 1)
                                        {
                                                q.push({i, j});
                                                vis[i][j] = true;
                                        }
                                }
                        }
                }
                int delRow[] = {-1, 1, 0, 0};
                int delCol[] = {0, 0, 1, -1};
                while (!q.empty())
                {
                        int row = q.front().first;
                        int col = q.front().second;
                        q.pop();
                        for (int i = 0; i < 4; i++)
                        {
                                int rown = row + delRow[i];
                                int coln = col + delCol[i];
                                if (rown >= 0 && rown < n && coln >= 0 && coln < m &&
                                    board[rown][coln] == 1 && vis[rown][coln] == false)
                                {
                                        q.push({rown, coln});
                                        vis[rown][coln] = true;
                                }
                        }
                }
                int cnt = 0;
                for (int i = 0; i < n; i++)
                {
                        for (int j = 0; j < m; j++)
                        {
                                if (board[i][j] == 1 && vis[i][j] == false)
                                        cnt++;
                        }
                }
                return cnt;
        }
};