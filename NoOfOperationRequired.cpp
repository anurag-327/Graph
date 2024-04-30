class DisjointSet
{
public:
        vector<int> parent, rank, size;
        DisjointSet(int V)
        {
                rank.resize(V, 0);
                size.resize(V, 1);
                parent.resize(V);
                for (int i = 0; i < V; i++)
                {
                        parent[i] = i;
                }
        }
        int findParent(int node)
        {
                if (parent[node] == node)
                        return node;
                return parent[node] = findParent(parent[node]); // path compression
        }
        void unionByRank(int u, int v)
        {
                int ulp_u = findParent(u);
                int ulp_v = findParent(v);
                if (ulp_u == ulp_v)
                        return;
                if (rank[ulp_u] < rank[ulp_v])
                {
                        parent[ulp_u] = ulp_v;
                }
                else if (rank[ulp_v] < rank[ulp_u])
                {
                        parent[ulp_v] = ulp_u;
                }
                else
                {
                        parent[ulp_v] = ulp_u;
                        rank[ulp_u]++;
                }
        }
        void unionBySize(int u, int v)
        {
                int ulp_u = findParent(u);
                int ulp_v = findParent(v);
                if (ulp_u == ulp_v)
                        return;
                if (size[ulp_u] < size[ulp_v])
                {
                        parent[ulp_u] = ulp_v;
                        size[ulp_v] += size[ulp_u];
                }
                else
                {
                        parent[ulp_v] = ulp_u;
                        size[ulp_u] += size[ulp_v];
                }
        }
};
class Solution
{
public:
        int makeConnected(int n, vector<vector<int>> &connections)
        {
                DisjointSet ds(n);
                int extraEdges = 0;
                for (auto it : connections)
                {
                        int u = it[0];
                        int v = it[1];
                        if (ds.findParent(u) == ds.findParent(v))
                        {
                                extraEdges++;
                                continue;
                        }
                        ds.unionBySize(u, v);
                }
                int cnt = 0;
                for (int i = 0; i < n; i++)
                {
                        if (ds.parent[i] == i)
                                cnt++;
                }
                int ans = cnt - 1;
                return ans <= extraEdges ? ans : -1;
        }
};