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

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       
        int one_to_next=0;
        ListNode* pl1 = l1;
        ListNode* pl2 = l2;
        vector<ListNode*>sum;
        
        if((l1->val == 0) && (l2->val == 0) && (l1->next ==nullptr) && (l2->next ==nullptr)) 
        {
            return l1;
        }
        while((pl2 != NULL) || (pl1!= NULL))
        {   
            if(pl1 && pl2)            
            { 
                int value = pl1->val + pl2->val + one_to_next;
                one_to_next =0;
                pl1->val = value;
                if((pl1->val) >=10)
                {
                    one_to_next =(pl1->val)/10;
                    pl1->val = (pl1->val)%10;
                }
                sum.push_back(pl1);
                pl1 = pl1->next;
                pl2= pl2->next;
            }
            else if (pl1 && (!pl2))
            {
                int value = pl1->val + one_to_next;
                one_to_next =0;
                pl1->val = value;
                if((pl1->val) >=10)
                {
                    one_to_next =(pl1->val)/10;
                    pl1->val = (pl1->val)%10;
                }
                sum.back()->next =  pl1;
                sum.push_back(pl1);
                pl1 = pl1->next;
            }
            else 
            {
                int value = pl2->val + one_to_next;
                one_to_next =0;
                pl2->val = value;
                if((pl2->val) >=10)
                {
                    one_to_next =(pl2->val)/10;
                    pl2->val = (pl2->val)%10;
                }
                sum.back()->next =  pl2;
                sum.push_back(pl2);
                pl2 = pl2->next;
            }
               
        }
        if(one_to_next !=0)
        {   
            ListNode* need_to_be_added = new ListNode(one_to_next);
            sum.back()->next = need_to_be_added;
            sum.push_back(need_to_be_added);
        }
  
        return sum[0];
        
    }
};

this code is simply equivalent to =>
     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
     {
        int one_to_next=0;
        ListNode* dummyHead = new ListNode(0);
        ListNode* sum = dummyHead;
       
        while((l2 != NULL) || (l1!= NULL) || (one_to_next !=0 ) )
        {   
            int x = l1 ? l1->val : 0;
            int y = l2 ? l2->val : 0;
            int value = x + y + one_to_next;
            one_to_next = value / 10;
            sum->next = new ListNode(value % 10);
            sum = sum->next;
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;    
        }
        return dummyHead->next;
     }
