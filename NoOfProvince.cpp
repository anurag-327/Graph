class Solution
{
public:
        void bfs(int i, vector<vector<int>> adj, int vis[], int V)
        {
                vis[i] = 1;
                // ans.push_back(node);
                for (int j = 1; j <= V; j++)
                {
                        if (vis[j] == 0 && adj[i][j] == 1)
                        {
                                bfs(j, adj, vis, V);
                        }
                }
        }

        int numProvinces(vector<vector<int>> adj, int V)
        {
                // code here// Code here
                int vis[V] = {0};
                int ans = 0;
                // vis[0]=1;
                for (int i = 0; i < V; i++)
                {
                        if (vis[i] == 0)
                        {
                                bfs(i, adj, vis, V);
                                ans++;
                        }
                }
                return ans;
        }
};