int prims(vector<pair<int, int>> adj[], int v, int e, int src)
{
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> vis(v + 1, 0);
        pq.push({0, src});
        int sum = 0;
        while (!pq.empty())
        {
                int node = pq.top().second;
                int dis = pq.top().first;
                if (vis[node] == 1)
                        continue; // already in mst
                vis[node] = 1;
                sum += dis;
                for (auto it : adj[node])
                {
                        // works on assumption that add all edges to pq but only those get added which are smaller
                        int adjnode = it.first;
                        int adjdis = it.second;
                        if (vis[adjnode] == 0)
                        { // node is not part of array so take it in mst and add it to pq so that it can be added if it has small wt
                                pq.push({adjdis, adjnode})
                        }
                }
        }
}