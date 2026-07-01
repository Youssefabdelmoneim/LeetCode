class Solution
{
public:
  int m, n;
  vector<vector<int>> memo;
  int maximalSquare(vector<vector<char>> &matrix)
  {
    m = matrix.size(), n = matrix[0].size();
    memo = vector<vector<int>>(m, vector<int>(n, -1));

    int res = 0;
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        res = max(res, fun(matrix, i, j));
      }
    }
    return res * res;
  }
  int fun(vector<vector<char>> &matrix, int i, int j)
  {
    if (i == m || j == n || matrix[i][j] == '0')
      return 0;
    if (memo[i][j] != -1)
      return memo[i][j];
    int below = fun(matrix, i + 1, j);
    int right = fun(matrix, i, j + 1);
    int diagonal = fun(matrix, i + 1, j + 1);
    int a = 1 + min(below, min(right, diagonal));
    return memo[i][j] = a;
  }
};