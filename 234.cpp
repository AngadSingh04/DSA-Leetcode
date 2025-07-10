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
        ListNode* prev = NULL;
        ListNode* nxt = NULL;

        while(curr!=NULL){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }

        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast!=NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* sh = revR(slow);
        ListNode* fh = head;

        while(sh!=NULL){
            if(sh->val != fh->val){
                return false;
            }
            sh = sh->next;
            fh = fh->next;
        }

        return true;


    }
};