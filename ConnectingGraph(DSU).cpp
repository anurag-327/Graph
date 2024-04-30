int Solve(int n, vector<vector<int>> &edges)
{
        // code here
        DisjointSet ds(n);
        int extraedges = 0;
        for (auto it : edges)
        {
                int u = it[0];
                int v = it[1];
                if (ds.findParent(u) == ds.findParent(v))
                        extraedges++;
                else
                        ds.unionBySize(u, v);
        }
        int cc = 0;
        for (int i = 0; i < n; i++)
        {
                if (ds.findParent(i) == i) // ultimate parent
                        cc++;
        }
        int ans = cc - 1;
        if (extraedges >= ans)
                return cc - 1;
        return -1;
}