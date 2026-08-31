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
    ListNode* insertionSortList(ListNode* head) {

        if(head == NULL){
            return head;
        }
        ListNode* curr = head->next;
        
        while(curr != NULL){
            ListNode* prev = NULL;
            ListNode* bigVal = NULL;
            ListNode* temp = head;
            int flag = 0;

            while(temp != curr){
                if(temp->val > curr->val && flag == 0){
                    flag = 1;
                    bigVal = temp;
                }
                if(flag == 0){
                    prev = temp;
                } 
                if(temp->next == curr){
                    break;
                }
                temp = temp->next;
            }

            if(flag == 1){
                temp->next = curr->next;
                curr->next = bigVal;
                if(prev != NULL){
                    prev->next = curr;
                }
                else{
                    head = curr;
                }
                
                curr = temp->next;
                
                
            }
            else{
                curr = curr->next;
            }

            
            
        }
        return head;
    }
};