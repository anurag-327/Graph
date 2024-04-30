int numProvinces(vector<vector<int>> adj, int V)
{
        // code here
        DisjointSet ds(V);
        for (int i = 0; i < V; i++)
        {
                for (int j = 0; j < V; j++)
                {
                        if (adj[i][j] == 1)
                        {
                                ds.unionByRank(i, j);
                        }
                }
        }
        int cnt = 0;
        // we are finding no of unique ultimate parents
        for (int i = 0; i < V; i++)
        {
                if (ds.findParent(i) == i) // ultimate parent
                        cnt++;
        }
        return cnt;
}