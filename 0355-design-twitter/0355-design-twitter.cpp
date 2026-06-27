class Twitter
{
public:
  unordered_map<int, priority_queue<int, vector<int>, greater<int>>> tweets;
  unordered_map<int, int> tweetByTime;
  unordered_map<int, unordered_set<int>> following;
  int time;

  Twitter()
  {
    time = 0;
  }

  void postTweet(int userId, int tweetId)
  {
    time++;
    tweets[userId].push(time);
    tweetByTime[time] = tweetId;
  }

  vector<int> getNewsFeed(int userId)
  {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    auto pq = tweets[userId];
    while (!pq.empty())
    {
      minHeap.push(pq.top());
      pq.pop();
      if (minHeap.size() > 10) // remove the 11th
        minHeap.pop();
    }
    for (auto followee : following[userId])
    {
      auto pq = tweets[followee];
      while (!pq.empty())
      {
        minHeap.push(pq.top());
        pq.pop();
        if (minHeap.size() > 10) // remove the 11th
          minHeap.pop();
      }
    }
    vector<int> vec;
    while (!minHeap.empty())
    {
      vec.push_back(tweetByTime[minHeap.top()]);
      minHeap.pop();
    }
    reverse(vec.begin(), vec.end());
    return vec;
  }

  void follow(int followerId, int followeeId)
  {
    if (followerId != followeeId)
      following[followerId].insert(followeeId);
  }

  void unfollow(int followerId, int followeeId)
  {
    if (followerId != followeeId)
      following[followerId].erase(followeeId);
  }
};
