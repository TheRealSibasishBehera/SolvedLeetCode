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
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *head1 = l1;
    ListNode *head2 = l2;

    ListNode *temp=new ListNode();
    ListNode *dummy = temp;

    if (!l1 && !l2)
        return nullptr;
    int remain = 0;
    while(head1 && head2){
        int ans = head1->val + head2->val + remain;

        remain = ans / 10;
        ans = ans % 10;

        ListNode *temp2 = new ListNode(ans);
        temp->next = temp2;
        temp = temp->next;
            head2=head2->next;
            head1=head1->next;
        
        
    }
    if(head1){
        while(head1){
            int ans = head1->val + remain;
        remain = ans / 10;
        ans = ans % 10;
            ListNode *temp2 = new ListNode(ans);
            temp->next = temp2;
            temp = temp->next;
            head1=head1->next;
            
        }
        
    }

    if(head2){
        while(head2){
            int ans = head2->val + remain;
        remain = ans / 10;
        ans = ans % 10;
            ListNode *temp2 = new ListNode(ans);
            temp->next = temp2;
            temp = temp->next;
            head2=head2->next;
        }
        
    }

    if(remain!=0){
        ListNode *temp2 = new ListNode(remain);
        temp->next = temp2;
        temp = temp->next;
    }   

    return dummy->next;
}
};