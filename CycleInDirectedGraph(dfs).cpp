bool dfs(int src, vector<int> adj[], vector<bool> &vis, vector<bool> &pathvis)
{
        vis[src] = true;
        pathvis[src] = true;
        for (auto it : adj[src])
        {
                if (!vis[it])
                {
                        if (dfs(it, adj, vis, pathvis))
                                return true;
                }
                else if (pathvis[it])
                {
                        return true;
                }
        }
        pathvis[src] = false;
        return false;
}
bool isCyclic(vector<vector<int>> &edges, int v, int e)
{
        // Write your code here
        vector<int> adj[v];
        vector<bool> vis(v, false);
        vector<bool> pathvis(v, false);
        for (auto it : edges)
        {
                int u = it[0];
                int v = it[1];
                adj[u].push_back(v);
        }
        for (int i = 0; i < v; i++)
        {
                if (!vis[i])
                {
                        if (dfs(i, adj, vis, pathvis))
                                return true;
                }
        }
        return false;
}