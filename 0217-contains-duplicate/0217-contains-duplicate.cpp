class Solution
{
public:
  bool containsDuplicate(vector<int> &nums)
  {
    unordered_map<int, bool> exist;
    for (auto num : nums)
    {
      if (exist[num] == 1)
        return true;
      exist[num] = 1;
    }
    return false;
  }
};