import java.util.ArrayList;
import java.util.Stack;

public class Leetcode206_Reverse_Linked_List extends ListNode{

    public static ListNode reverseList(ListNode head) {

        ListNode reverse = null;

        while(head != null){
            ListNode next = head.next;
            head.next = reverse;
            reverse = head;
            head = next;
        }
        return reverse;
    }

    public static void main(String[] args) {
        // write your code here

        ListNode head = new ListNode();
        ListNode ptr = head;
        int[] array = new int[] {1,2,3,4,5};

        for(int num : array){
            ptr.next = new ListNode();
            ptr = ptr.next;
            ptr.val = num;
        }
        reverseList(head.next);
    }
}
