class Solution
{
public:
        vector<int> eventualSafeNodes(vector<vector<int>> &graph)
        {
                int n = graph.size();
                vector<int> outdegree(n, 0);
                unordered_map<int, vector<int>> m;
                for (int i = 0; i < n; i++)
                {
                        for (auto it : graph[i])
                        {
                                m[it].push_back(i);
                        }
                        outdegree[i] = graph[i].size();
                }
                vector<int> ans;
                vector<int> visited(n, 0);
                while (true)
                {
                        bool flag = 0;
                        for (int i = 0; i < n; i++)
                        {
                                if (!visited[i] && outdegree[i] == 0)
                                {
                                        ans.push_back(i);
                                        visited[i] = 1;
                                        flag = 1;
                                        for (auto it : m[i])
                                                outdegree[it]--;
                                }
                        }
                        if (!flag)
                                break;
                }
                sort(ans.begin(), ans.end());
                return ans;
        }
};