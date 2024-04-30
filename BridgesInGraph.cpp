class Solution
{
        int timer = 1;

public:
        void dfs(vector<int> adj[], vector<int> &vis, int time[], int ltime[], int node, int parent, vector<vector<int>> &bridges)
        {
                vis[node] = 1;
                time[node] = ltime[node] = timer;
                timer++;
                for (auto it : adj[node])
                {
                        if (it == parent)
                                continue;
                        if (vis[it] == 0)
                        {
                                dfs(adj, vis, time, ltime, it, node, bridges);
                                // updating based on min of neighbours
                                ltime[node] = min(ltime[node], ltime[it]);
                                if (ltime[it] > time[node])
                                {
                                        // no other way to reach it
                                        // so it-> node is a bridge
                                        bridges.push_back({node, it});
                                }
                        }
                        else
                        {
                                // already bridge so you cannot be bridge so just upadte min
                                ltime[node] = min(ltime[node], ltime[it]);
                        }
                }
        }
        vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
        {
                vector<int> adj[n];
                vector<int> vis(n, 0);
                int time[n], ltime[n];
                vector<vector<int>> bridges;
                for (auto it : connections)
                {
                        adj[it[0]].push_back(it[1]);
                        adj[it[1]].push_back(it[0]);
                }
                dfs(adj, vis, time, ltime, 0, -1, bridges);
                return bridges;
        }
};