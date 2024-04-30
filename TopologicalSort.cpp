class Solution
{
public:
        // Function to return list containing vertices in Topological order.
        void dfs(int v, vector<int> adj[], stack<int> &s, int vis[])
        {
                vis[v] = 1;
                for (auto child : adj[v])
                {
                        if (vis[child] == 0)
                        {
                                dfs(child, adj, s, vis);
                        }
                }
                s.push(v);
        }
        vector<int> topoSort(int V, vector<int> adj[])
        {
                // code here
                int vis[V] = {0};
                stack<int> s;
                dfs(0, adj, s, vis);
                for (int i = 0; i < V; i++)
                {
                        if (vis[i] == 0)
                        {
                                dfs(i, adj, s, vis);
                        }
                }
                vector<int> ans;
                while (!s.empty())
                {
                        ans.push_back(s.top());
                        s.pop();
                }
                return ans;
        }
};