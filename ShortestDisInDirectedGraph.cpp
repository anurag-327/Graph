vector<int> shortestPathInDAG(int n, int m, vector<vector<int>> &edges)
{
        vector<pair<int, int>> adj[n];
        for (auto it : edges)
        {
                adj[it[0]].push_back({it[1], it[2]});
        }
        queue<int> q;
        q.push(0);
        vector<int> topo;
        vector<int> dis(n, INT_MAX);
        dis[0] = 0;
        while (!q.empty())
        {
                int node = q.front();
                q.pop();
                for (auto it : adj[node])
                {
                        if (dis[node] + it.second < dis[it.first])
                        {
                                dis[it.first] = it.second + dis[node];
                                q.push(it.first);
                        }
                }
        }
        for (int i = 0; i < n; i++)
        {
                if (dis[i] == INT_MAX)
                        dis[i] = -1;
        }
        return dis;
}