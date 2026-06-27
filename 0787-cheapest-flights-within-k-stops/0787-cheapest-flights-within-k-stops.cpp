class Solution
{
public:
  int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
  {
    vector<int> distance(n, 100001);
    distance[src] = 0;

    for (int i = 0; i <= k; i++)
    {
      auto tmp = distance;
      for (auto flight : flights)
      {
        int u = flight[0], v = flight[1], w = flight[2];
        if (distance[u] + w < tmp[v])
        {
          tmp[v] = w + distance[u];
        }
      }
        distance = tmp;
    }
    return distance[dst] == 100001 ? -1 : distance[dst];
  }
};