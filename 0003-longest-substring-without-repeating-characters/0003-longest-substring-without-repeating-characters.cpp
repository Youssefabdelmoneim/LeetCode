
class Solution
{
public:
  int lengthOfLongestSubstring(string s)
  {

    int l = 0, res = 0;
    unordered_map<char, int> idx;
    

    for (int i = 0; i < s.length(); i++)
    {
      if (idx.count(s[i]) && idx[s[i]] >= l) // character  exist in our path
        l = idx[s[i]] + 1;
      res = max(res, i - l + 1);
      idx[s[i]] = i;
    }
    return res;
  }
};