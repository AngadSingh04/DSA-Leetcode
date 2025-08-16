/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        
        // if(list1 != null && list2 != null){
        //     if(list1.val > list2.val){
        //         list2.next = mergeTwoLists(list1, list2.next);
        //         return list2;
        //     }else{
        //         list1.next = mergeTwoLists(list1.next, list2);
        //         return list1;
        //     }

        // }

        //     if(list1 == null){
        //         return list2;
        //     }
        //     return list1;

        ListNode dummy = new ListNode(-1);
        ListNode curr = dummy;

        while(list1 != null && list2 != null){
            if(list1.val < list2.val){
                curr.next = list1;
                list1 = list1.next;
            }else{
                curr.next = list2;
                list2 = list2.next;
            }
            curr = curr.next;
        }

        if(list1 != null){
            curr.next = list1;
        }else{
            curr.next = list2;
        }

        return dummy.next;

    }
}

//
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ansNode = new ListNode(-1);
        ListNode* tmp = ansNode;

        while(list1!=NULL && list2!=NULL){
            if(list1->val < list2->val){
                tmp->next = list1;
                tmp = list1;
                list1 = list1->next;

            }else{
                tmp->next = list2;
                tmp = list2;
                list2 = list2->next;
            }
        }

        if(list1!=NULL){
            tmp->next = list1;
        }
        if(list2!=NULL){
            tmp->next = list2;
        }

        return ansNode->next;
    }
};