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
  {
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