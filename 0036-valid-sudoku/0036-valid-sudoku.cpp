class Solution
{
public:
  bool isValidSudoku(vector<vector<char>> &board)
  {
    int row = board.size(), col = board[0].size();
    for (int i = 0; i < row; i++)
    {
      vector<bool> v(9, 0);

      for (int j = 0; j < col; j++)
      {
        if (board[i][j] == '.')
          continue;
        if (v[board[i][j] - '1'])
          return false;
        v[board[i][j] - '1'] = 1;
      }
    }
    for (int i = 0; i < col; i++)
    {
      vector<bool> v(9, 0);
      for (int j = 0; j < row; j++)
      {
        if (board[j][i] == '.')
          continue;
        if (v[board[j][i] - '1'])
          return false;
        v[board[j][i] - '1'] = 1;
      }
    }

    for (int k = 0; k < 3; k++)
    {
      for (int m = 0; m < 3; m++)
      {
        vector<bool> v(9, 0);
        for (int i = 0; i < 3; i++)
        {
          for (int j = 0; j < 3; j++)
          {

            int rowIdx = k * 3 + i, colIdx = m * 3 + j;
            if (board[rowIdx][colIdx] == '.')
              continue;
            if (v[board[rowIdx][colIdx] - '1'])
              return false;
            v[board[rowIdx][colIdx] - '1'] = 1;
          }
        }
      }
    }
    return true;
  }
};