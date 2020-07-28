import java.util.PriorityQueue;

class Leetcode703_KthLargest {

    PriorityQueue<Integer> pq = new PriorityQueue<>();
    int k;

    public Leetcode703_KthLargest(int k, int[] nums) {
        this.k = k;
        for(int num : nums){
            pq.offer(num);
            if(pq.size() > k)
                pq.poll();
        }
    }

    public int add(int val) {
        pq.add(val);
        if(pq.size() >k)
            pq.poll();
        return pq.peek();
    }

    public static void main(String[] args) {
        // write your code here

        int k = 3;
        int[] nums = {4,5,8,2};
        Leetcode703_KthLargest obj = new Leetcode703_KthLargest(k,nums);
        int param_1 = obj.add(3);
        int param_2 = obj.add(5);
        int param_3 = obj.add(10);
        int param_4 = obj.add(9);
        int param_5 = obj.add(4);

    }

}

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest obj = new KthLargest(k, nums);
 * int param_1 = obj.add(val);
 */
