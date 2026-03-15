class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int cnt = 0;
        ListNode* temp = head;

        while (temp != NULL) {
            cnt++;
            temp = temp->next;
        }

        int k = cnt - n; 
        if (k == 0) return head->next;

        temp = head;
        for (int i = 0; i < k - 1; i++) { 
            temp = temp->next;
        }

        temp->next = temp->next->next;
        return head;
    }
};