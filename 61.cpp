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
    public ListNode rotateRight(ListNode head, int k) {
        if(head == null || head.next == null || k==0){
            return head;
        }

        ListNode temp = head;
        int count = 1;
        while(temp.next != null){
            temp = temp.next;
            count=count+1;
        }
        temp.next = head;
        int st = count - (k%count);
        ListNode ntail = temp;
        while(st != 0){
            ntail = ntail.next;
            st = st - 1;
        }
        ListNode nhead = ntail.next;
        ntail.next = null;
        return nhead;
    }
}