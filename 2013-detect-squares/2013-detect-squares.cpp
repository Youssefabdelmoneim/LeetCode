
class DetectSquares
{
public:
  unordered_map<int, vector<int>> um;
  unordered_map<int, unordered_map<int, int>> freq;

  DetectSquares()
  {

  }

  void add(vector<int> point)
  {
    um[point[1]].push_back(point[0]);
    freq[point[0]][point[1]]++;
  }

  int count(vector<int> point)
  {
    int x = point[0], y = point[1];
    int res = 0;
    for (auto xx : um[y])
    {
      if (xx == x)
        continue;
      int len = xx - x;
      int a = freq[x][y + len], b = freq[xx][y + len];
      res += a * b;
      a = freq[x][y - len], b = freq[xx][y - len];
      res += a * b;
    }
    return res;
  }
};