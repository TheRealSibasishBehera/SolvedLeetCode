/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
Node *copyRandomList(Node *head)
{
    if (!head)
        return head;
    Node *temp = head;
    Node *dummy = new Node(0);
    Node *copy = dummy;
    // vector<ListNode*,>  v;
    unordered_map<Node *, Node *> m;
    while(temp){
        Node* temp2=new Node(temp->val);

        m[temp]=temp2;
        // Node* random = temp->random;
        dummy->next=temp2;
        dummy=dummy->next;
        temp=temp->next;
    }


    for (auto x : m)
    {
      if (x.first->random) {
        x.second->random = m[x.first->random];
    } else {
        x.second->random = nullptr;  // Handle the case where x.first->random is nullptr
    }
    }
    
    return copy->next;
}
};