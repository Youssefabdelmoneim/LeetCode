class Solution
{
public:
  int longestOnes(vector<int> &nums, int k)
  {
    int n = nums.size();
    int res = 0;
    int l = 0;
    for (int r = 0; r < n; r++)
    {
      if (nums[r] == 0)
      {
        k--;
        if (k < 0)
        {
          while (nums[l] != 0) // start after first zero
            l++;
          l++;
          k = 0;
        }
      }
      res = max(r - l + 1, res);
    }
    return res;
  }
};