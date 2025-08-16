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
    ListNode* reverseList(ListNode* tmp){
        ListNode* curr = tmp;
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

    ListNode* getNode(ListNode* tmp, int k){
        while(tmp!=NULL && k > 0){
            tmp = tmp->next;
            k--;
        }
        return tmp;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* tmp = head;
        ListNode* prevNode = NULL;

        while(tmp!=NULL){
            ListNode* kthNode = getNode(tmp,k-1);
            if(kthNode == NULL){
                if(prevNode != NULL){
                    prevNode -> next = tmp;
                    break;
                }
            }

            ListNode* nextNode = kthNode->next;
            kthNode->next = NULL;

            ListNode* nHead = reverseList(tmp);
            if(tmp == head){
                head = nHead;
            }else{
                prevNode->next = nHead;
            }

            prevNode = tmp;
            tmp = nextNode;
        }

        return head;
    }
};