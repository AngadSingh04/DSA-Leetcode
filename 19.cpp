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
        ListNode* temp1 = head;
        ListNode* pre = NULL;
        int count = 0;

        while(temp!=NULL){
            count++;
            temp = temp->next;
        }

        int ind = count - n;
        int tmp = 0;

        if(ind==0){
            ListNode* newN = head->next;
            delete head;
            return newN;
        }

        while(tmp!=ind && temp1!=NULL){
            pre = temp1;
            temp1 = temp1->next;
            tmp++;
        }

        pre->next = temp1->next;
        delete temp1;

        return head;


    }
};