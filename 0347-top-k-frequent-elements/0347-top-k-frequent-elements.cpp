class Solution
{
public:
  vector<int> topKFrequent(vector<int> &nums, int k)
  {
    unordered_map<int, int> um;
    int n = nums.size();
    for (auto num : nums)
    {
      um[num]++;
    }

    vector<vector<int>> maxFreqElements(n + 1);
    for (auto val : um)
    {
      maxFreqElements[val.second].push_back(val.first);
    }

    vector<int> res;
    for (int i = n; i >= 1; i--)
    {
      for (auto el : maxFreqElements[i])
      {
        if (k > 0)
        {
          res.push_back(el);
          k--;
        }
      }
    }
    return res;
  }
};