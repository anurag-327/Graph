vector<int> adj[nodes];
int indegree[nodes] = {0};
vector<int> topo;
queue<int> q;
for (auto it : graph)
{
        int u = it[0];
        int v = it[1];
        indegree[v]++;
        adj[u].push_back(v);
}
for (int i = 0; i < nodes; i++)
{
        if (indegree[i] == 0)
                q.push(i);
}
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
return topo;