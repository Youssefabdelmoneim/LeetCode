class Solution {
public:
  string generate_key(string s) {
    // o(n) time , o(1) space
    int count[26] = {};
    for (auto c : s)
      count[c - 'a']++;
    string key = "";
    for (int i = 0; i < 26; i++)
      key += "#" + to_string(count[i]);
    return key;
  }

  vector<vector<string>> groupAnagrams(vector<string> &strs) {

    vector<vector<string>> res;
    unordered_map<string, vector<string>> r;

    for (auto str : strs) {

      string key = generate_key(str);
      r[key].push_back(str);
    }

    for (auto val : r)
      res.push_back(val.second);

    return res;
  };
};