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
    public void reorderList(ListNode head) {
        if(head == null || head.next == null){
            return;
        }

        ListNode fast = head;
        ListNode slow = head;
        while(fast != null && fast.next != null){
            fast = fast.next.next;
            slow = slow.next;
        }

        ListNode sh = reverseList(slow.next);
        slow.next = null;
        ListNode fh = head;

        while(sh != null){
            ListNode temp1 = fh.next;
            ListNode temp2 = sh.next;
            fh.next = sh;
            sh.next = temp1;

            fh = temp1;
            sh = temp2;
        }

    }

    public ListNode reverseList(ListNode head){

        ListNode nxt = null;
        ListNode pre = null;
        ListNode curr = head;

        while(curr != null){
            nxt = curr.next;
            curr.next = pre;
            pre = curr;
            curr = nxt;
        }

        return pre;
    }
}