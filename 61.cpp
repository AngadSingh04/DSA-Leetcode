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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        int size = 1;
        ListNode* len = head;
        while(len->next!=NULL){
            len = len->next;
            size++;
        }

        if(k%size == 0){
            return head;
        }
        
        len->next = head;

        int n = size - k%size; 
        ListNode* tmp = len;
        while(n != 0){
            tmp = tmp->next;
            n--;
        }

        ListNode* nHead = tmp->next;
        tmp->next = NULL;

        return nHead;


        
    }
};