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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* leftPrev = NULL;
        ListNode* rightNext = NULL;

        ListNode* temp = head;
        ListNode* prev = NULL;
    
        int count = 1;

        if(right == left){
            return head;
        }

        while(temp != NULL ){
            if(count == left){
                leftPrev = prev;
            }
            if(count == right ){
                rightNext = temp->next;
                break;
            }
            count++;
            prev = temp;
            temp = temp->next;
        }

        

        prev = rightNext;
        ListNode* next = NULL;
        ListNode* curr = NULL;

        if(leftPrev == NULL){
            curr = head;
        }
        else{
            curr = leftPrev->next;
        }

        while(curr != rightNext){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        if(leftPrev != NULL){
            leftPrev->next = prev;
            return head;
        }
        else{
            return prev;
        }

        
    }
};