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

    bool isPalindrome(ListNode* head) {
        stack<int> values;
        ListNode* phead = head;
        while(phead)
        {
            values.push(phead->val);
            phead = phead->next;
        }
        
        phead = head;
        while(phead){ 
            if(phead->val != values.top())
            {
                return false;
            }   
            values.pop();
            phead = phead->next;
        }
        return true ;
    }
};
