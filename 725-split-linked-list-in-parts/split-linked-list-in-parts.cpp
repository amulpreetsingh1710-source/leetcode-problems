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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans;

        if(head == NULL){
            for(int i = 0; i< k; i++){
                ans.push_back(NULL);   
            } 
            return ans;
        }
        ListNode* temp = head;
        int count = 0;

        while(temp != NULL){
            count++;
            temp = temp->next;
        }

        int r = count % k;
        ListNode* next = NULL;
        ListNode* prev = head;

        if(k > count){
            ListNode* temp = head;
            
            while(temp != NULL){
                next = temp->next;
                temp->next = NULL;
                ans.push_back(temp);
                temp = next;
            }

            for(int i = 0; i< k-count;i++){
                ans.push_back(NULL);
            }

        }
        else if(k< count && r!= 0){
            int p = ceil(double(count)/k);
            ListNode* temp = head;
            int cnt = 0;
            while(temp != NULL){
                cnt++;
                if(cnt == p && r!= 0){
                    r--;
                    next = temp->next;
                    temp->next = NULL;
                    ans.push_back(prev);
                    prev = next;
                    temp = next;
                    cnt = 0;
                    continue;
                }
                else if(cnt == p-1 && r == 0){
                    next = temp->next;
                    temp->next = NULL;
                    ans.push_back(prev);
                    prev = next;
                    temp = next; 
                    cnt = 0;
                    continue;
                }
                temp =temp->next;
            }
        }
        
        else if(r == 0){
            ListNode* temp = head;
            int c = 0;
            while(temp != NULL){
                
                c++;
                if(c == count/k){
                    next = temp->next;
                    temp->next = NULL;
                    ans.push_back(prev);
                    prev = next;
                    temp = next;
                    c = 0;
                    continue;
                }
                
                temp = temp->next;
            }

        }
        return ans;
    }
};