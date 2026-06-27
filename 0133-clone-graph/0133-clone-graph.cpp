/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution
{
public:
  Node *cloneGraph(Node *node)
  {
    if ( !node) return node;
    unordered_map<Node *, Node *> clone;
    clone[node] = new Node(node->val);
    queue<Node *> q;
    q.push(node);
    while (!q.empty())
    {
      auto node = q.front();
      q.pop();
      for (auto neighbor : node->neighbors)
      {
        if (!clone[neighbor]) // not visited yet
        {
          clone[neighbor] = new Node(neighbor->val);
          q.push(neighbor);
        }
          clone[node]->neighbors.push_back(clone[neighbor]);

      }
    }
    return clone[node];
  }
};