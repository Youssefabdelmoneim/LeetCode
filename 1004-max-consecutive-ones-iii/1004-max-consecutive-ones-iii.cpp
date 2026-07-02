class Solution
{
public:
  int longestOnes(vector<int> &nums, int k)
  {
    int n = nums.size();
    int curr = 0;
    int res = 0;
    queue<int> q; // number of 1's between zeros
    int numberOfOnesBetweenZeros = 0;
    for (int i = 0; i < n; i++)
    {
      if (nums[i] == 0)
      {
        q.push(numberOfOnesBetweenZeros);
        numberOfOnesBetweenZeros = 0;
        k--;
        if (k < 0)
        {
          curr -= q.front() + 1;
          q.pop();
          k++;
        }
      }
      curr++;
      res = max(curr, res);
      if ( nums[i] == 1)numberOfOnesBetweenZeros++;
    }
    return res;
  }
};