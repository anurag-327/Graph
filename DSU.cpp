#include <bits/stdc++.h>
using namespace std;
class DisjointSet
{
        vector<int> parent, rank, size;

public:
        DisjointSet(int V)
        {
                rank.resize(V + 1, 0);
                size.resize(V + 1, 1);
                parent.resize(V + 1);
                for (int i = 0; i <= V; i++)
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
int main()
{
        DisjointSet ds(7);
        ds.unionBySize(1, 2);
        ds.unionBySize(2, 3);
        ds.unionBySize(5, 6);
        if (ds.findParent(4) == ds.findParent(5))
                cout << "Same Component" << endl;
        else
                cout << "Different Component" << endl;
        ds.unionBySize(4, 5);
        if (ds.findParent(4) == ds.findParent(5))
                cout << "Same Component" << endl;
        else
                cout << "Different Component" << endl;
}