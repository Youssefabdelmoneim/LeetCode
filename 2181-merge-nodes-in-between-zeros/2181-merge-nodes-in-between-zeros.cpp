/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
  ListNode *mergeNodes(ListNode *head)
  {
    ListNode *dummy = new ListNode();
    head = head->next;
    auto h = dummy;
    int sum = 0;
    while (head != nullptr)
    {
      if (head->val == 0)
      {
        h->next = new ListNode(sum);
        sum = 0;
        h = h->next;
      }
      sum += head->val;
      head = head -> next;
    }
    return dummy->next;
  }
};