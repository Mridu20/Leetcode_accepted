/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *heada, ListNode *headb) {
        int cnta=0;
        int cntb=0;

        ListNode* tempa = heada;
        ListNode*  tempb = headb;

        while(tempa != NULL && tempb != NULL){
            cnta++;
            cntb++;

            tempa = tempa->next;
            tempb = tempb->next;
        }

        while(tempa != NULL){
            cnta++;
            tempa = tempa->next;
        }

        while(tempb != NULL){
            cntb++;
            tempb = tempb->next;
        }

        tempb = headb;
        tempa = heada;
        if(cnta > cntb){
            int diff = cnta-cntb;
            
            while(diff--){
                tempa = tempa->next;
            }
        }
        else{
            int diff = cntb-cnta;
            
            while(diff--){
                tempb = tempb->next;
            }
        }

        while(tempa && tempb){
            if(tempa == tempb)return tempa;

            tempa = tempa->next;
            tempb = tempb->next;
        }

        return NULL;
    }
};