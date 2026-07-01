class Solution
{
public:
  // intuitive : the maximum subarray = total - minimumSubArray
  //  the key here that if the minimum is wrapping we know for sure that the maximum isn't

  // edge case that if all numbers are negative the minimumSubArray will take the total which wil make the result invalid
  int maxSubarraySumCircular(vector<int> &nums)
  {
    int n = nums.size();
    int globalMax = nums[0];
    int globalMin = nums[0];
    int currMax = 0, currMin = 0;
    int total = 0;
    for (int i = 0; i < n; i++)
    {
      total += nums[i];
      currMax += nums[i];
      currMin += nums[i];
      globalMax = max(globalMax, currMax);
      globalMin = min(globalMin, currMin);
      currMin = min(0, currMin); // if the currMin is positive we will set it to 0 so it's better to don't take the previous elements
      currMax = max(0, currMax); // if the currMax  is negative we will set it to 0  so it's better to don't take the previous elements
    }
    if (globalMax < 0) // all elements are negative
    {
      return globalMax;
    }
    return (max(globalMax, total - globalMin)); // non - wrapping subarray and  wrapping subarray 
  }
};