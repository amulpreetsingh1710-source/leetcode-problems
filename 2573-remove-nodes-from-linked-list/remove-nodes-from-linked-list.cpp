class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        if (head == NULL) return NULL;

        // Step 1: First Reverse
        ListNode* temp = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;

        while(temp != NULL){
            next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }
        head = prev;

        // Step 2: Filtering elements using a fixed max_val tracking variable
        int max_val = head->val; // Keep track of the absolute maximum seen so far
        temp = head->next;
        prev = head;

        while(temp != NULL){
            if(temp->val < max_val){ // Compare against the global max, not just prev->val
                prev->next = temp->next;
                // delete temp;
                temp = prev->next;
            }
            else{
                max_val = temp->val; // Update the max seen so far
                prev = temp;
                temp = temp->next;
            }
        }

        // Step 3: Second Reverse to restore original relative order
        temp = head;
        prev = NULL;
        next = NULL;

        while(temp != NULL){
            next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }

        return prev;
    }
};
