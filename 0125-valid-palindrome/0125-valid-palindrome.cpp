
class Solution {
public:
  bool alphanumeric(char c) {
    return (c <= '9' && c >= '0' || c <= 'z' && c >= 'a' ||
            c <= 'Z' && c >= 'A');
  }
  bool isPalindrome(string s) {
    int l = 0, r = s.length() - 1;
    while (l < r) {

      char c1 = s[l], c2 = s[r];

      while (l < r && !alphanumeric(s[l]))
        l++;
      while (l < r && !alphanumeric(s[r]))
        r--;

      s[r] = tolower(s[r]);
      s[l] = tolower(s[l]);

      if (s[l] != s[r])
        return false;
      l++, r--;
    }
    return true;
  }
};