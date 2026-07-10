class Solution
{
public:
  int evalRPN(vector<string> &tokens)
  {
    stack<int> st;
    for (auto token : tokens)
    {

      if (token == "+")
      {
        int v2 = st.top();
        st.pop();
        int v1 = st.top();
        st.pop();
        st.push(v2 + v1);
      }
      else if (token == "-")
      {
        int v2 = st.top();
        st.pop();
        int v1 = st.top();
        st.pop();
        st.push(v1 - v2);
      }
      else if (token == "*")
      {
        int v2 = st.top();
        st.pop();
        int v1 = st.top();
        st.pop();
        st.push(v2 * v1);
      }
      else if (token == "/")
      {
        int v2 = st.top();
        st.pop();
        int v1 = st.top();
        st.pop();

        st.push(v1 / v2);
      }
      else st.push(stoi(token));
    }
    return st.top();
  }
};