#include <bits/stdc++.h>
int shortestPathBinaryMatrix(vector<vector<int>> &matrix, pair<int, int> src, pair<int, int> dest)
{
        // normal bfs updating levels
        if (matrix[src.first][src.second] == 0)
                return -1;
        if (src.first == dest.first && src.second == dest.second)
                return 0;
        int n = matrix.size();
        int m = matrix[0].size();
        queue<pair<int, pair<int, int>>> q;
        vector<vector<int>> dis(n, vector<int>(m, INT_MAX));
        int delRow[4] = {0, 0, 1, -1};
        int delCol[4] = {1, -1, 0, 0};
        q.push({0, {src.first, src.second}});
        dis[src.first][src.second] = 0;
        while (!q.empty())
        {
                int dist = q.front().first;
                int x = q.front().second.first;
                int y = q.front().second.second;
                q.pop();
                for (int i = 0; i < 4; i++)
                {
                        int nbrx = x + delRow[i];
                        int nbry = y + delCol[i];
                        if (nbrx >= 0 && nbrx < n && nbry >= 0 && nbry < m && matrix[nbrx][nbry] == 1 && (dist + 1 < dis[nbrx][nbry]))
                        {
                                dis[nbrx][nbry] = 1 + dist;
                                if (nbrx == dest.first && nbry == dest.second)
                                {
                                        return dist + 1;
                                }
                                q.push({dist + 1, {nbrx, nbry}});
                        }
                }
        }
        return -1;
}