class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *head1 = l1;
        ListNode *head2 = l2;

        ListNode *dummy = new ListNode();
        ListNode *temp = dummy;

        int remain = 0;

        while (head1 || head2 || remain) {
            int sum = remain;

            if (head1) {
                sum += head1->val;
                head1 = head1->next;
            }

            if (head2) {
                sum += head2->val;
                head2 = head2->next;
            }

            remain = sum / 10;
            temp->next = new ListNode(sum % 10);
            temp = temp->next;
        }

        return dummy->next;
    }
};
