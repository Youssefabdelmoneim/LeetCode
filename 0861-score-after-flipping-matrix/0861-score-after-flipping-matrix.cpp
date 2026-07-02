class Solution
{
public:
  int m, n;
  int matrixScore(vector<vector<int>> &grid)
  {
    m = grid.size(), n = grid[0].size();
    for (int i = 0; i < m; i++)
    {
      if (grid[i][0] == 0)
        for (int j = 0; j < n; j++) // optimal
        {
          grid[i][j] = !grid[i][j];
        }
    }
    for (int j = 0; j < n; j++)
    {
      int count = 0;
      for (int i = 0; i < m; i++)
      {
        count += grid[i][j];
      }
      if (2 * count < m) // optimal
        for (int i = 0; i < m; i++)
        {
          grid[i][j] = !grid[i][j];
        }
    }

    int res = 0;
    for (int j = 0; j < n; j++)
    {
      int deg = 1 << (n - j - 1);
      int count = 0;
      for (int i = 0; i < m; i++)
      {
        count += grid[i][j];
      }
      res += deg * count;
    }

    return res;
  }
};
