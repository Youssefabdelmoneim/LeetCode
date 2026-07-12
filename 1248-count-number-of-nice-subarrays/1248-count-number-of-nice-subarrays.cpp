class Solution
{
public:
  int numberOfSubarrays(vector<int> &nums, int k)
  {
    int n = nums.size();
    queue<int> q;
    int res = 0;
    int subArrays = 0;
    int l = 0;
    for (int r = 0; r < n; r++)
    {
      if (nums[r] % 2 != 0)
      {
        k--;
        subArrays = 0;
      }

      while (k == 0)
      {
        if (nums[l] % 2 != 0)
          k++;
        subArrays++;
        l++;
      }

      res += subArrays;
    }

    return res;
  }
};