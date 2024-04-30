vector<int> bellmanFordDist(vector<vector<int>> adj, int n, int src)
{
        // simply just iterate n-1 times and relax edges
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        for (int i = 0; i < n - 1; i++)
        {
                for (auto it : adj)
                {
                        int u = it[0];
                        int v = it[1];
                        int wt = it[2];
                        if (dis[u] != INT_MAX && dist[u] + wt < dist[v])
                        {
                                dist[v] = dist[u] + wt;
                        }
                }
        }
        return dist;
}
bool bellmanFordCheckNegativecycle(vector<vector<int>> adj, int n, int src)
{
        // simply just iterate n-1 times and relax edges and iterate one more time if anything gets updated then it has neg cycle
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        for (int i = 0; i < n - 1; i++)
        {
                for (auto it : adj)
                {
                        int u = it[0];
                        int v = it[1];
                        int wt = it[2];
                        if (dis[u] != INT_MAX && dist[u] + wt < dist[v])
                        {
                                dist[v] = dist[u] + wt;
                        }
                }
        }
        for (auto it : adj)
        {
                int u = it[0];
                int v = it[1];
                int wt = it[2];
                if (dis[u] != INT_MAX && dist[u] + wt < dist[v])
                {
                        return true;
                }
        }
        return false;
}