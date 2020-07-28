import java.util.HashMap;
import java.util.PriorityQueue;

public class Leetcode347_Top_K_Frequent_Elements {


    private static class Item{
        int data;
        int freq;

        Item(int data, int freq){
            this.data = data;
            this.freq = freq;
        }
    }
    public static int[] topKFrequent(int[] nums, int k) {

        int[] answer = new int[k];
        int index = 0;

        HashMap<Integer,Integer> hashmap = new HashMap<>();

        for(int num : nums){
            hashmap.put(num,hashmap.getOrDefault(num,0)+1);
        }

        PriorityQueue<Item> que = new PriorityQueue<>(hashmap.size(), (a,b) ->{
            return b.freq - a.freq;
        });

        for(int key : hashmap.keySet()){
            que.add(new Item(key,hashmap.get(key)));
        }

        while(k-- > 0){
            Item it = que.poll();
            answer[index++] = it.data;
        }
        return answer;
    }

    public static void main(String[] args) {
        // write your code here
        int[] nums = {1,1,1,2,2,3};
        int k = 2;
        int[] answer = topKFrequent(nums,k);
    }
}
