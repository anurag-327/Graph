class Solution
{
public:
        // Function to detect cycle in an undirected graph.

        bool checkcycle(int v, vector<int> adj[], int vis[])
        {
                queue<pair<int, int>> q;
                q.push({v, -1});
                vis[v] = 1;
                while (!q.empty())
                {
                        int node = q.front().first;
                        int parent = q.front().second;
                        q.pop();
                        for (auto it : adj[node])
                        {
                                if (vis[it] == 0)
                                {
                                        vis[it] = 1;
                                        q.push({it, node});
                                }
                                else if (vis[it] == 1 && it != parent)
                                {
                                        return true;
                                }
                        }
                }
                return false;
        }

        bool isCycle(int v, vector<int> adj[])
        {
                // Code here
                int vis[v] = {0};
                bool loop = false;
                for (int i = 0; i < v; i++)
                {
                        if (vis[i] == 0)
                        {
                                if (checkcycle(i, adj, vis) == true)
                                {
                                        return true;
                                }
                        }
                }
                return false;
        }
};

class Solution
{
public:
        // Function to detect cycle in an undirected graph.

        bool checkcycle(int v, int parent, vector<int> adj[], int vis[])
        {
                vis[v] = 1;
                bool loopexist;
                for (auto it : adj[v])
                {
                        if (vis[it] == 1 && it != parent)
                        {
                                return true;
                        }
                        else if (vis[it] == 0)
                        {
                                if (checkcycle(it, v, adj, vis) == true)
                                        return true;
                        }
                }
                return false;
        }

        bool isCycle(int v, vector<int> adj[])
        {
                // Code here
                int vis[v] = {0};
                bool loop = false;
                for (int i = 0; i < v; i++)
                {
                        if (vis[i] == 0)
                        {
                                if (checkcycle(i, adj, vis) == true)
                                {
                                        return true;
                                }
                        }
                }
                return false;
        }
};