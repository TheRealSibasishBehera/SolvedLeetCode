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

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    ListNode *head1 = list1;
    ListNode *head2 = list2;

    
    if(!list1 && !list2) return nullptr;
    if(!list1 ) return list2;
    if(!list2) return list1;
    // initiasise
    ListNode *temp;
    ListNode *dummy;

    int big = 0;

    if (head1->val > head2->val)
    {
        temp = new ListNode(head2->val);
        head2 = head2->next;
        big = 2;
    }
    else
    {
        temp = new ListNode(head1->val);
        head1 = head1->next;
        big = 1;
    }

    dummy = temp;
    while (head1 && head2)
    {
        if (head1->val > head2->val)
        {
            ListNode *tempo = new ListNode(head2->val);
            dummy->next = tempo;
            dummy = dummy->next;
            head2 = head2->next;
        }else{
            ListNode *tempo = new ListNode(head1->val);
            dummy->next = tempo;
            dummy = dummy->next;
            head1 = head1->next;
        }
    }

    while(head1){
        ListNode *tempo = new ListNode(head1->val);
        dummy->next = tempo;
        dummy = dummy->next;
        head1 = head1->next;
    }
    while(head2){
        ListNode *tempo = new ListNode(head2->val);
        dummy->next = tempo;
        dummy = dummy->next;
        head2 = head2->next;
    }   



    return temp;
}
};