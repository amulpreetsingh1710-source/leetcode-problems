class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        // Dummy heads for the two separate chains      //stack memory location
        ListNode lessHead(0);
        ListNode greaterHead(0);
        
        // Pointers to track the tails of both chains
        ListNode* lessTail = &lessHead;
        ListNode* greaterTail = &greaterHead;
        
        ListNode* curr = head;
        
        while (curr != nullptr) {
            if (curr->val < x) {
                lessTail->next = curr;      // Append to the less chain
                lessTail = lessTail->next;  // Move the tail forward
            } else {
                greaterTail->next = curr;   // Append to the greater/equal chain
                greaterTail = greaterTail->next; // Move the tail forward
            }
            curr = curr->next;
        }
        
        // Crucial step: Cut off the end of the greater chain to prevent cycles
        greaterTail->next = nullptr;
        
        // Connect the end of the 'less' chain to the start of the 'greater' chain
        lessTail->next = greaterHead.next;  // cause first NOde in dummy node is 0 i.e why lesshead.next;
        
        // The new head is the first element after the 'less' dummy node
        return lessHead.next; // cause first NOde in dummy node is 0 i.e why lesshead.next
    }
};
