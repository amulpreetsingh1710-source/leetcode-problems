class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Create a dummy head to easily attach new nodes
        ListNode dummy(0); 
        ListNode* curr = &dummy;
        int carry = 0;
        
        // Loop runs as long as there is data in either list OR a leftover carry
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry;
            
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }
            
            // Calculate new carry and the digit to store
            carry = sum / 10;
            curr->next = new ListNode(sum % 10);
            
            // Move our result pointer forward
            curr = curr->next;
        }
        
        return dummy.next;
    }
};
