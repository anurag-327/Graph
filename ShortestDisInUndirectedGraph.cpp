vector<int> shortestPath(int n, vector<vector<int>> &edges, int src)
{
        // Write your code here.
        vector<int> adj[n];
        for (auto it : edges)
        {
                adj[it[0]].push_back(it[1]);
                adj[it[1]].push_back(it[0]);
        }
        queue<int> q;
        vector<int> dis(n, INT_MAX);
        vector<bool> vis(n, false);
        q.push(src);
        vis[src] = true;
        dis[src] = 0;
        while (!q.empty())
        {
                int front = q.front();
                q.pop();
                for (auto it : adj[front])
                {
                        if (dis[front] + 1 < dis[it])
                        {
                                dis[it] = 1 + dis[front];
                                q.push(it);
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