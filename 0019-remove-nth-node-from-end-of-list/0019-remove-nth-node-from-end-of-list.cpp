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
ListNode *removeNthFromEnd(ListNode *head, int n)
{
    // we need length 
    //in 0 based indexing we need to remove n-1
    // we need to be in length-n-1

    if(!head) return head;
    // if(n==1) return head->next;
    ListNode *temp = head;
    int length = 0;
    while (temp)
    {
        length++;
        temp = temp->next;
    }
        if(length==1 && n==1) return head->next;

    temp = head;
    
    int required_index = length -n -1;
    if(required_index == -1) return head->next;
    int c =0;
    while(c!= required_index ){
        temp=temp->next;
        c++;
    }

    temp->next = temp->next->next;
    return head;

}
};