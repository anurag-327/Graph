class Solution
{
public:
        vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
        {
                int n = image.size();
                int m = image[0].size();
                int delRow[4] = {-1, 1, 0, 0};
                int delCol[4] = {0, 0, -1, 1};
                queue<pair<int, int>> q;
                q.push({sr, sc});
                int initialColor = image[sr][sc];
                image[sr][sc] = color;
                while (!q.empty())
                {
                        int row = q.front().first;
                        int col = q.front().second;
                        q.pop();
                        for (int i = 0; i < 4; i++)
                        {
                                int rown = row + delRow[i];
                                int coln = col + delCol[i];
                                // recolor all neighbours whose color is initial color and are have not been colored already
                                if (rown >= 0 a && rown < n && coln >= 0 && coln < m && image[rown][coln] == initialColor && image[rown][coln] != color)
                                {
                                        image[rown][coln] = color;
                                        q.push({rown, coln});
                                }
                        }
                }
                return image;
        }
};