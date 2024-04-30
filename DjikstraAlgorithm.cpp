vector<int> djikstra(vector<pair<int, int>> adj[], int v, int e, int src)
{
        vector<int> dis(v + 1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        dis[src] = 0;
        pq.push({0, src});
        while (!pq.empty())
        {
                int node = pq.top().second;
                int nodedis = pq.top().first;
                pq.pop();
                for (auto nbr : adj[node])
                {
                        int nbrnode = nbr.first;
                        int wt = nbr.second;
                        if (nodedis + wt < dis[nbrnode])
                        { // if chance of getting updated update it and push to pq to explore later
                                dis[nbrnode] = nodedis + wt;
                                pq.push({dis[nbrnode], nbrnode});
                        }
                }
        }
        return dis;
}