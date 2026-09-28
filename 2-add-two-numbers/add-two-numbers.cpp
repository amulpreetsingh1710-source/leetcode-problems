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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* n1 = l1;
        ListNode* n2 = l2;

        while(n1 != NULL && n2 != NULL){
            n1 = n1->next;
            n2 = n2->next;
        }

        ListNode* head;

        if(n1 == NULL){
            head = l2;
        }
        else{
            head = l1;
        }

        n1 = l1;
        n2 = l2;

        ListNode* add = head;

        int c = 0;
        int r = 0;
        int sum = 0;

        while(n1 != NULL && n2 != NULL){

            if(c > 0){
                sum = n1->val + n2->val + c;
            }
            else{
                sum = n1->val + n2->val;
            }

            r = sum % 10;
            c= sum / 10;

            add->val = r;
            if(add->next == NULL && c > 0){
                add->next = new ListNode(c);
                add = add->next;
                add = add->next;
                break;
            }
            add = add->next;

            n1 = n1->next;
            n2 = n2->next;

        } 

        while(add != NULL){
            if(c > 0){
                sum = add->val + c;

                r = sum % 10;
                c = sum / 10;

                add->val = r;
                if(add->next == NULL && c > 0){
                    add->next = new ListNode(c);
                    break;
                }
                add = add->next;
            }
            else{
                break;
            }

        }
        return head;
        
    }
};