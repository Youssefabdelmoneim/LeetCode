class Solution
{
public:
  vector<vector<int>> threeSum(vector<int> &nums)
  {
    int n = nums.size();
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++)
    {
      if (i > 0 && nums[i] == nums[i - 1]) // same target same result
        continue;
      int target = -nums[i];
      int l = i + 1, r = n - 1;
      while (l < r)
      {
        if (nums[l] + nums[r] < target)
        {
          l++;
        }
        else if (nums[l] + nums[r] > target)
        {
          r--;
        }
        else
        {
          res.push_back({nums[l], nums[i], nums[r]});
          l++, r--;
          while (l < n && nums[l] == nums[l - 1]) //same second value potential to generate same result
            l++;
        }
      }
    }
    return res;
  }
};