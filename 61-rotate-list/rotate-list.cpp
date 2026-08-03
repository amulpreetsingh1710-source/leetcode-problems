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

        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode* temp = head;
        int count = 0;
        
        while(temp != NULL){            
            temp = temp->next;
            count+= 1;
        }

        ListNode* prev = NULL;
        temp = head;

        k = k % count;
        if(k == 0){
            return head;
        }
        for(int i = 0; i< count-k; i++){
            prev = temp;
            temp = temp->next; 
        }

        ListNode* tail = temp;
        while(tail->next != NULL){
            tail = tail->next;
        }

        tail->next = head;
        ListNode* newHead = prev->next;
        prev->next = NULL;
        
        return newHead;

    }
};