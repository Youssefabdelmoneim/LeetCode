class Solution
{
public:
  int search(vector<int> &nums, int target)
  {
    int l1 = 0;
    int r1 = splitPoint(nums) - 1;
    int l2 = r1 + 1, r2 = nums.size() - 1;

    while (l1 <= r1)
    {
      int mid = l1 + (r1 - l1) / 2;
      if (nums[mid] == target)
        return mid;
      else if (nums[mid] > target)
        r1 = mid - 1;
      else if (nums[mid] < target)
        l1 = mid + 1;
    }
    while (l2 <= r2)
    {
      int mid = l2 + (r2 - l2) / 2;
      if (nums[mid] == target)
        return mid;
      else if (nums[mid] > target)
        r2 = mid - 1;
      else if (nums[mid] < target)
        l2 = mid + 1;
    }

    return -1;
  }
  int splitPoint(vector<int> &nums)
  {
    int n = nums.size();
    int l = 0, r = n - 1;
    while (l < r)
    {
      int mid = l + (r - l) / 2;
      if (nums[mid] < nums[r])
      {
        r = mid;
      }
      else
      {
        l = mid + 1;
      }
    }
    return r;
  }
};
