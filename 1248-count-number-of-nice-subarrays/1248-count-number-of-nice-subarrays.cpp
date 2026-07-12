class Solution
{
public:
  int numberOfSubarrays(vector<int> &nums, int k)
  {
    queue<int> q;
    int res = 0, countEven = 0;
    for (auto num : nums)
    {
      if (num % 2 == 0)
        countEven++;
      else
      {

        q.push(countEven); // number of even numbers before this odd number
        countEven = 0;
        k--;
      }

      if (k < 0) // another odd number that exceeds our window so remove first odd number 
      {
        q.pop();
        k = 0;
      }
      if (k == 0) // valid window so we 'll add all subarrays that we can get from this window
      {
        res += q.front() + 1; // number of evens before first odd number in our window + 1
      }
    }
    return res;
  }
};