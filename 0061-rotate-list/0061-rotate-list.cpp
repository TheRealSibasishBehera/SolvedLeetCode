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
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        if (k==0 ||  head == nullptr || head->next==nullptr)
        {
            return head;
        }
         int count = 0;
        ListNode *temp3= head;
        while (temp3)
        {
            temp3 = temp3->next;
            count++;
        }

        //basically rottate for k times using for loop O(k*l)
        for (int i = 0; i < k%count; i++)
        {
            ListNode *temp = head->next;
            ListNode *temp2 = head;
            while (temp->next)
            {
                temp=temp->next;
                temp2=temp2->next;
            }
            temp2->next=nullptr;
            temp->next=head;
            head=temp;
            
        }

        return head;
    }
};