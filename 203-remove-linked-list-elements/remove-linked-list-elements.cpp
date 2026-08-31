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
    ListNode* removeElements(ListNode* head, int val) {

        ListNode* temp = NULL;
        ListNode* prev = NULL;

        while(head != NULL && head->val == val){
            temp = head;
            head = head->next;
            delete temp;
        }

        temp = head;

        while(temp != NULL){

            if(temp->val == val){  
                prev->next = prev->next->next;
                delete temp;
                temp = prev->next;
                continue;
            }
            prev = temp;
            temp = temp->next;
        }
        return head;
    }
};