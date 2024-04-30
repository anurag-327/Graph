class Solution
{
public:
        // Function to detect cycle in a directed graph.
        // if we can generate toposort then it is directed graph
        bool isCyclic(int v, vector<int> adj[])
        {
                // code here
                int count = 0;
                queue<int> q;
                vector<int> indegree(v, 0);
                for (int i = 0; i < v; i++)
                {
                        for (auto it : adj[i])
                        {
                                indegree[it]++;
                        }
                }

                for (int i = 0; i < v; i++)
                {
                        if (indegree[i] == 0)
                        {
                                q.push(i);
                        }
                }
                vector<int> ans;
                while (!q.empty())
                {
                        int node = q.front();
                        q.pop();
                        ans.push_back(node);

                        for (auto it : adj[node])
                        {
                                indegree[it]--;
                                if (indegree[it] == 0)
                                {
                                        q.push(it);
                                }
                        }
                        count++;
                }
                if (count == v)
                        return false;
                else
                        return true;
        }
};