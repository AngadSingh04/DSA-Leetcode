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
    public boolean isPalindrome(ListNode head) {
        if(head == null || head.next == null){
            return true;
        }

        ListNode fast = head;
        ListNode slow = head;

        while(fast != null && fast.next != null){
            slow = slow.next;
            fast = fast.next.next;
        }

        ListNode sh = reverseList(slow);
        ListNode fh = head;

        while(sh != null){
            if(fh.val != sh.val){
                return false;
            }
            fh =fh.next;
            sh = sh.next;
        }

        return true;
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