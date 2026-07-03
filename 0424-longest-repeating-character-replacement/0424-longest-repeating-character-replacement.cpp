class Solution
{
public:
  int characterReplacement(string s, int k)
  {
    int l = 0;
    vector<int> vec(26, 0);
    int res = 0;
    for (int r = 0; r < s.length(); r++)
    {
      vec[s[r] - 'A']++;
      int mostFreq = 0;
      for (auto val : vec)
        mostFreq = max(mostFreq, val);
      int tmp = r - l + 1;
      if (tmp - mostFreq <= k)
      {
        res = max(res, tmp);
      }
      else
      {
        vec[s[l] - 'A']--; // remove first character in the window
        l++;
      }
    }
    return res;
  }
};