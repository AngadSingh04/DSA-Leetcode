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
    ListNode* revR(ListNode* head){
        ListNode* curr = head;
        ListNode* nxt = NULL;
        ListNode* prev = NULL;

        while(curr!=NULL){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast!=NULL && fast->next!=NULL){
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* sh = revR(slow->next);
        slow->next = NULL;
        ListNode* fh = head;

        while(sh!=NULL){
            ListNode* temp1 = fh->next;
            ListNode* temp2 = sh->next;

            fh->next = sh;
            sh->next = temp1;

            fh = temp1;
            sh = temp2;
        }
    }
};