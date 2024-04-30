class Solution
{
public:
        bool bfs(int src, vector<vector<int>> &graph, vector<int> &color)
        {

                queue<int> q;
                q.push(src);
                color[src] = 0;
                while (!q.empty())
                {
                        int front = q.front();
                        q.pop();
                        for (auto it : graph[front])
                        {
                                if (color[it] == -1)
                                {
                                        color[it] = 1 - color[front];
                                        q.push(it);
                                }
                                else if (color[it] == color[front])
                                {
                                        return false;
                                }
                        }
                }
                return true;
        }
        bool isBipartite(vector<vector<int>> &graph)
        {
                int n = graph.size();
                vector<int> color(n, -1);
                for (int i = 0; i < n; i++)
                {
                        if (color[i] == -1)
                        {
                                if (bfs(i, graph, color) == false)
                                {
                                        return false;
                                }
                        }
                }
                return true;
        }
};
class Solution
{
public:
        bool bfs(int src, vector<vector<int>> &graph, vector<int> &color)
        {
                if (color[src] == -1)
                        color[src] = 0;
                for (auto it : graph[src])
                {
                        if (color[it] == -1)
                        {
                                color[it] = 1 - color[src];
                                if (!bfs(it, graph, color))
                                        return false;
                        }
                        else if (color[it] == color[src])
                        {
                                return false;
                        }
                }
                return true;
        }
        bool isBipartite(vector<vector<int>> &graph)
        {
                int n = graph.size();
                vector<int> color(n, -1);
                for (int i = 0; i < n; i++)
                {
                        if (color[i] == -1)
                        {
                                if (bfs(i, graph, color) == false)
                                {
                                        return false;
                                }
                        }
                }
                return true;
        }
};