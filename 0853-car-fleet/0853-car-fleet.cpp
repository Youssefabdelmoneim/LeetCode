class Solution
{
public:
  int carFleet(int target, vector<int> &position, vector<int> &speed)
  {
    unordered_map<int, double> time;
    for (int i = 0; i < position.size(); i++)
    {
      time[position[i]] = double(target - position[i]) / speed[i];

    }
    stack<double> st;
    sort(position.rbegin(), position.rend());
    for (auto pos : position)
    {

      if (st.empty())
      {
        st.push(time[pos]);
      }
      else  if (time[pos] > st.top())
      
      {
          st.push(time[pos]);
      }
    }
    return st.size();
  }
};