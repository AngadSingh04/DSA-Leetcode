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
    int getGCD(int a, int b){
        if(b==0){
            return a;
        }
        return getGCD(b, a%b);
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode* tmp = head;

        while(tmp!=NULL && tmp->next!=NULL){
            ListNode* curr = tmp;
            ListNode* nxtt = curr->next;
            int gcd = getGCD(curr->val, nxtt->val);
            ListNode* tt = new ListNode(gcd);
            curr->next = tt;
            tt->next = nxtt;
            tmp = nxtt;
        }

        return head;
    }
};