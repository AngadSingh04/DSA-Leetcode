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
        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode* tmp = head;
        int count = 1;
        while(tmp->next!=NULL){
            tmp = tmp ->next;
            count++;
        }
        tmp->next = head;

        int rem_rotations = count - (k%count);
        ListNode* tail = tmp;
        while(rem_rotations != 0){
            tail = tail->next;
            rem_rotations--;
        }

        ListNode* newHead = tail->next;
        tail->next = NULL;
        return newHead;
        
    }
};