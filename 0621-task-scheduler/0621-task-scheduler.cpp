class Solution
{
public:
  int leastInterval(vector<char> &tasks, int n)
  {
    vector<int> freq(26, 0);
    for (auto task : tasks)
    {
      freq[task - 'A']++;
    }
    priority_queue<int> pq;
    for (auto f : freq)
    {
      if (f > 0)
        pq.push(f);
    }
    queue<pair<int, int>> q;
    int time = 0;

    while (!pq.empty() || !q.empty())
    {
      if (!q.empty() && q.front().first == time)
      {
        pq.push(q.front().second);
        q.pop();
      }
      if (!pq.empty())
      {
        int val = pq.top() - 1;
        pq.pop();
        if (val > 0)
          q.push({time + n + 1, val});
      }
      time++;
    }
    return time;
  }
};