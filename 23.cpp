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
    class compare{
        public:
        bool operator()(const auto& a, const auto& b){
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;

        if(lists.size() == 0){
            return NULL;
        }

        ListNode* head = NULL;
        ListNode* tail = NULL;

        for(int i = 0; i < lists.size(); i++){
            if(lists[i] != NULL){
                pq.push(lists[i]);
            }
        }

        while(!pq.empty()){
            ListNode* tmp = pq.top();
            pq.pop();
            if(tail == NULL){
                head = tmp;
                tail = tmp;
                if(tmp->next!=NULL){
                    pq.push(tmp->next);
                }
            }else{
                tail->next = tmp;
                tail = tail->next;

                if(tmp->next!=NULL){
                    pq.push(tmp->next);
                }
            }
        }
        return head;
    }
};