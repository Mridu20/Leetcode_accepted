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
        if(head == NULL || head->next == NULL)return head;
        int cnt = 1;
        ListNode* temp = head;
        while(temp && temp->next){
            cnt++;
            temp = temp->next;
        }

        k = k%cnt;
        if(k == 0)return head;
        k = cnt - k;
        temp->next = head;
        temp = head;
        while(k>1){
            temp = temp->next;
            k--;
        }

        head = temp->next;
        temp->next = NULL;

        return head;
    }
};