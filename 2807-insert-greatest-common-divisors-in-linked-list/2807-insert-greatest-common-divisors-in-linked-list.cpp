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
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
    
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head == NULL || head->next ==NULL)return head;
        ListNode* temp = head;
        ListNode* front = head->next;

        while(front != NULL){
            int a = gcd(temp->val, front->val);
            temp->next = new ListNode(a, front);

            temp = front;
            if(front != NULL)front = front->next; 
        }

        return head;
    }
};