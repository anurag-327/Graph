int kosaraju(vector<int> adj[], int n)
{
        // for strongly connected components
        // sort all nodes in order of finishing time ie. topsort
        // transpose the graph
        // dfs acc to toposort
        vector<int> vis(n, 0);
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
                if (vis[i] == 0)
                {
                        topodfs(i, adj, st, vis);
                }
        }
        // creating transpose adjacency list
        vector<int> transpose[n];
        for (int i = 0; i < n; i++)
        {
                vis[i] = 0; // remarking 0 for dfs
                for (auto it : adj[i])
                {
                        transpose[it].push_back(i);
                }
        }
        // traversing on dfs
        int count = 0;
        while (!st.empty())
        {
                int node = st.top();
                st.pop();
                if (vis[i] == 0)
                {
                        dfs(transpose, node, vis);
                        count++;
                }
        }
        return count;
}