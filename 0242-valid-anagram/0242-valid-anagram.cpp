class Solution
{
public:
  bool isAnagram(string s, string t)
  {
    vector<int> vec(26, 0);
    for (char ch : s)
    {
      vec[ch - 'a']++;
    }
    for (char ch : t)
    {
      vec[ch - 'a']--;
    }

    for (int i = 0; i < 26; i++)
    {
      if (vec[i] != 0)
        return false;
    }
    return true;
  }
};