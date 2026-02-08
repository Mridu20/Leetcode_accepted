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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* temp = head;
        int cnt = 0;

        while(temp != NULL){
            cnt++;
            temp = temp->next;
        }

        cnt /=2;

        temp = head;

        if(head == NULL || head->next == NULL){
            return NULL;
        }
        ListNode* prev = NULL;
        while(cnt>0){
            cnt--;
            prev = temp;
            temp = temp->next;
        }

        prev->next = temp->next;
        // temp->next = NULL;
        // free(temp);

        return head;

    }
};