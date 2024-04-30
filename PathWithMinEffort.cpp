int minimumTimeTakingPath(vector<vector<int>> &heights)
{
        // Write your code here.
        int n = heights.size();
        int m = heights[0].size();
        int delRow[4] = {0, 0, 1, -1};
        int delCol[4] = {1, -1, 0, 0};
        vector<vector<int>> dis(n, vector<int>(m, INT_MAX));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0, 0}});
        dis[0][0] = 0;
        while (!pq.empty())
        {
                int dist = pq.top().first;
                int x = pq.top().second.first;
                int y = pq.top().second.second;
                pq.pop();
                if (x == n - 1 && y == m - 1)
                {
                        return dist;
                }
                for (int i = 0; i < 4; i++)
                {
                        int nbrx = x + delRow[i];
                        int nbry = y + delCol[i];

                        if (nbrx >= 0 && nbrx < n && nbry >= 0 && nbry < m)
                        {
                                int diff = max(abs(heights[x][y] - heights[nbrx][nbry]), dist);
                                if (diff < dis[nbrx][nbry])
                                {
                                        dis[nbrx][nbry] = diff;
                                        pq.push({diff, {nbrx, nbry}});
                                }
                        }
                }
        }
        return 0;
}