class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int car = 0;
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;

        ListNode* head = new ListNode();
        ListNode* temp = head;

        while (temp1 != NULL || temp2 != NULL || car) {
            int sum = car;

            if (temp1 != NULL) {
                sum += temp1->val;
                temp1 = temp1->next;
            }

            if (temp2 != NULL) {
                sum += temp2->val;
                temp2 = temp2->next;
            }

            temp->next = new ListNode(sum % 10);
            temp = temp->next;
            car = sum / 10;
        }

        return head->next;
    }
};