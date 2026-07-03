class Solution
{
public:
  bool checkInclusion(string s1, string s2)
  {

    int len = s1.length();
    string tmp1 = hashing(s1);
    int l = 0, r = s2.length() - 1;
    for (int i = 0; i + len  <= s2.length(); i++)
    {
      string tmp2 = hashing(s2.substr(i, len));
      if (tmp1 == tmp2)
        return true;
    }
    return false;
  }

  string hashing(string s)
  {class Solution
{
public:
  bool checkInclusion(string s1, string s2)
  {

    int len = s1.length();
    vector<int> tmp1(26, 0);
    vector<int> tmp2(26, 0);

    for (auto ch : s1)
      tmp1[ch - 'a']++;
    int l = 0;
    for (int i = 0; i < len && i < s2.length(); i++)
    {
      tmp2[i - 'a']++;
    }

    if (tmp1 == tmp2)
      for (int r = len; r < s2.length(); r++)
      {
        if (tmp1 == tmp2)
          tmp2[l++]--;
        tmp2[r - 'a']++;
      }
    return tmp1 == tmp2;
  }
};
    vector<int> vec(26, 0);
    string hashed = "";
    for (auto ch : s)
      vec[ch - 'a']++;
    for (int i = 0; i < 26; i++)
    {
      hashed += to_string(vec[i]) + '#';
    }
    return hashed;
  }
};