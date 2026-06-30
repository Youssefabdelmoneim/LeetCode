class Solution
{
public:
  vector<int> twoSum(vector<int> &nums, int target)
  {
    unordered_map<int, int> exist;
    for (int i = 0; i < nums.size(); i++)
    {
      if (exist.count(target - nums[i]))
      {
        int j = exist[target - nums[i]];
        return {min(i,j),max(i,j) };
      }
      exist[nums[i]] = i;
    }
    return {};
  }
};