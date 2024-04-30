#include <bits/stdc++.h>
int savingMoney(int n, int source, int destination, int K, vector<vector<int>> &trains)
{
        // Write your code here
        if (source == destination)
                return 0;
        vector<pair<int, int>> adj[n];
        vector<int> dis(n, INT_MAX);
        for (auto it : trains)
        {
                adj[it[0]].push_back({it[1], it[2]});
        }
        // priority_queue<pair<int, pair<int, int>>,vector<pair<int, pair<int, int>>>,greater<pair<int, pair<int, int>>>> q;
        queue<pair<int, int>> q;
        q.push({source, -1});
        dis[source] = 0;
        int ans = INT_MAX;
        while (!q.empty())
        {
                int node = q.front().first;
                int stops = q.front().second;
                q.pop();
                if (node == destination)
                {
                        if (stops <= K)
                        {
                                ans = min(ans, dis[node]);
                        }
                }
                for (auto it : adj[node])
                {
                        if (dis[node] + it.second < dis[it.first])
                        {
                                dis[it.first] = dis[node] + it.second;
                                q.push({it.first, stops + 1});
                        }
                }
        }
        return ans == INT_MAX ? -1 : ans;
}