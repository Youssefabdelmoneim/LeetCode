class Solution
{
public:
  string multiply(string num1, string num2)
  {
      if (num1 == "0" || num2 == "0") {
            return "0";
        }
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    vector<int> res(num1.length() + num2.length(), 0);
    for (int i = 0; i < num1.length(); i++)
    {
      for (int j = 0; j < num2.length(); j++)
      {
        int a = num1[i] - '0', b = num2[j] - '0';
        res[i + j] += a * b;
        res[i + j + 1] += res[i + j] / 10;
        res[i + j] %= 10;
      }
    }
    string r = "";
    bool start = false;
    for ( int j = res.size() - 1; j >= 0 ;j -- )
    {
      int val = res[j];
      if (val != 0)
        start = true;
      if (start)
      {
        r += to_string(val);
      }
    }
    return r;
  }
};
