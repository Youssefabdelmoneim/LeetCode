class Solution
{
public:
  int longestConsecutive(vector<int> &nums)
  {

    unordered_map<int, bool> exist;
    int res = 0;
    for (auto num : nums)
    {

      exist[num] = 1;
    }

    for (auto val : nums)
    {
      int tmp = 0;

      int num = val;
      while (exist[num])
      {
        exist[num] = 0;
        tmp++;
        num++;
      }
      num = val - 1;
      while (exist[num])
      {
        exist[num] = 0;

        tmp++;
        num--;
      }
      res = max(tmp, res);
    }
    return res;
  }
};