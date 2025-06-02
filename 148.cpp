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
    public ListNode sortList(ListNode head) {
        if(head == null || head.next==null){
            return head;
        }
        ListNode mid = midf(head);
        ListNode left = head;
        ListNode right = mid.next;
        mid.next = null;

        left = sortList(left);
        right = sortList(right);

        return merger(left,right);

    }
    public ListNode midf(ListNode head){
        ListNode slow = head;
        ListNode fast = head.next;
        while(fast!=null && fast.next!=null){
            fast = fast.next.next;
            slow = slow.next;
        }
        return slow;
    }

    public ListNode merger(ListNode h1, ListNode h2){
        ListNode tri = new ListNode(-1);
        ListNode curr = tri;

        while(h1!=null && h2!=null){
            if(h1.val < h2.val){
                curr.next = h1;
                h1=h1.next;
            }else{
                curr.next=h2;
                h2=h2.next;
            }
            curr = curr.next;
        }

        if(h1!=null){
            curr.next=h1;
        }else{
            curr.next=h2;
        }

        return tri.next;
    }
}