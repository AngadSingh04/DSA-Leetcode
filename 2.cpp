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

        
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;

        ListNode* temp3 = new ListNode(-1);
        ListNode* temp4 = temp3;
        int carry = 0;

        while(temp1!=NULL || temp2!=NULL){
            int val1 = 0;
            if(temp1!=NULL){
                val1 = temp1->val;
            }
            int val2 = 0;
            if(temp2!=NULL){
                val2 = temp2->val;
            }

            int sum = val1+val2+carry;
            carry = sum/10;
            sum = sum%10;
            temp4->next = new ListNode(sum);
            temp4 = temp4->next;

            if(temp1!=NULL){
                temp1 = temp1->next;
            }
            if(temp2!=NULL){
                temp2 = temp2->next;
            }
        }

        if(carry > 0){
            temp4->next = new ListNode(carry);
        }

        return temp3->next;



    }
};