class Solution
{
public:
  vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
  {
    int m = heights.size(), n = heights[0].size();
    vector<vector<bool>> pacific(m, vector<bool>(n, 0));
    auto atalantic = pacific;
    vector<pair<int, int>> vec = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    queue<pair<int, int>> p, a;
    for (int j = 0; j < n; j++)
    {
      pacific[0][j] = true;
      p.push({0, j});
      atalantic[m - 1][j] = true;
      a.push({m - 1, j});
    }
    for (int j = 0; j < m; j++)
    {
      pacific[j][0] = true;
      p.push({j, 0});
      atalantic[j][n - 1] = true;
      a.push({j, n - 1});
    }

    while (!p.empty())
    {
      auto val1 = p.front();
      p.pop();
      for (auto val2 : vec)
      {
        int i = val1.first + val2.first;
        int j = val1.second + val2.second;
        if (i < m && j < n && j >= 0 && i >= 0 && !pacific[i][j] && heights[i][j] >= heights[val1.first][val1.second])
        {
          pacific[i][j] = true;
          p.push({i, j});
        }
      }
    }

    while (!a.empty())
    {
      auto val1 = a.front();
      a.pop();
      for (auto val2 : vec)
      {
        int i = val1.first + val2.first;
        int j = val1.second + val2.second;
        if (i < m && j < n && j >= 0 && i >= 0 && !atalantic[i][j] && heights[i][j] >= heights[val1.first][val1.second])
        {
          atalantic[i][j] = true;
          a.push({i, j});
        }
      }
    }
    vector<vector<int>> res;
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (pacific[i][j] && atalantic[i][j])
        {
          res.push_back({i,j});
        }
      }
    }
    return res;
  }
};