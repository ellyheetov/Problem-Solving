import java.util.*;
import java.util.stream.Collectors;

public class Leetcode451_Sort_Characters_By_Frequency {
    public static String frequencySort(String s) {
        HashMap<Character, Integer> map = new HashMap<>();
        StringBuilder answer = new StringBuilder();

        for (Character c : s.toCharArray()) {
            map.put(c, map.getOrDefault(c, 0) + 1);
        }
        PriorityQueue<Map.Entry<Character, Integer>> maxHeap = new PriorityQueue<>((a, b) -> b.getValue() - a.getValue());
        maxHeap.addAll(map.entrySet());

        while(!maxHeap.isEmpty()){
            Map.Entry<Character,Integer> entry = maxHeap.poll();
            for(int i = 0;i< entry.getValue(); i++){
                answer.append(entry.getKey());
            }
        }
        return answer.toString();
    }

    public static void main(String[] args) {
        String s = "cccaaa";
        String answer = frequencySort(s);
        System.out.print(answer);
    }

}
