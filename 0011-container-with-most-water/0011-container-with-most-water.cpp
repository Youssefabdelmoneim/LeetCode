class Solution
{
public:
  int maxArea(vector<int> &heights)
  {
    int res = 0;
    int l = 0, r = heights.size() - 1;
    while (l < r)
    {

      if (heights[l] < heights[r])
      {
        res = max(res, heights[l] * (r - l));
        l++; // left bar became useless
      }
      else 
      {
        res = max(res, heights[r] * (r - l));
        r--; // right bar became useless
      }
    }
    return res;
  }
};