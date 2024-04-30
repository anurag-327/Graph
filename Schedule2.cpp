class Solution
{
public:
        vector<int> findOrder(int n, vector<vector<int>> &prerequisites)
        {
                vector<int> adj[n];
                vector<bool> vis(n, false);
                vector<int> indegree(n, 0);
                for (auto it : prerequisites)
                {
                        adj[it[1]].push_back(it[0]);
                        indegree[it[0]]++;
                }
                queue<int> q;
                for (int i = 0; i < n; i++)
                {
                        if (indegree[i] == 0)
                                q.push(i);
                }
                vector<int> topo;
                while (!q.empty())
                {
                        int front = q.front();
                        q.pop();
                        topo.push_back(front);
                        for (auto it : adj[front])
                        {
                                indegree[it]--;
                                if (indegree[it] == 0)
                                        q.push(it);
                        }
                }
                if (topo.size() == n)
                        return topo;
                return {};
        }
};