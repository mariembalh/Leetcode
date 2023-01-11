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
    ListNode* middleNode(ListNode* head) {
        if(head == NULL) return NULL;
        ListNode* phead = head;
        vector<ListNode*> midddle;
        midddle.push_back(phead);
        while(midddle.back()->next != NULL)
        {
            midddle.push_back(midddle.back()->next);
        }
        int size = midddle.size();
        return midddle[(size/2)];
       
    }
};
