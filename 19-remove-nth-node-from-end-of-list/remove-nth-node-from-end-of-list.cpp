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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        
        ListNode* temp = head;
        int count = 0;

        //counting total nodes
        while(temp!= NULL){
            temp = temp->next;
            count+= 1;
        }

        //deleting the node
        ListNode* prev = NULL;
        temp = head;
        for(int i = 0; i < (count-n); i++){
            prev = temp;
            temp = temp->next;
        }
        //if prev is NULL then point the head  to next node to avoid memory leak
        if(prev!= NULL){
            prev->next = temp->next;
            temp->next= NULL;
        }
        else{
            head = head->next;
        }
        delete temp;
        return head;
    }
};