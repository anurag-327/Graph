class Solution
{
public:
        bool canFinish(int n, vector<vector<int>> &prerequisites)
        {
                vector<int> adj[n];
                vector<bool> vis(n, false);
                vector<int> indegree(n, 0);
                for (auto it : prerequisites)
                {
                        adj[it[0]].push_back(it[1]);
                        indegree[it[1]]++;
                }
                queue<int> q;
                for (int i = 0; i < n; i++)
                {
                        if (indegree[i] == 0)
                                q.push(i);
                }
                int cnt = 0;
                while (!q.empty())
                {
                        int front = q.front();
                        q.pop();
                        cnt++;
                        for (auto it : adj[front])
                        {
                                indegree[it]--;
                                if (indegree[it] == 0)
                                        q.push(it);
                        }
                }
                return cnt == n ? true : false;
        }
};