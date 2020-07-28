import java.lang.reflect.Array;
import java.util.*;

public class Leetcode692_Top_K_Frequent_Words {

    private static class Diction {
        String str;
        int freq;

        Diction(String str, int freq) {
            this.str = str;
            this.freq = freq;
        }
    }

    public static List<String> topKFrequent(String[] words, int k) {

        List<String> answer = new ArrayList<>();
        HashMap<String, Integer> map = new HashMap<>();

        for (String word : words) {
            map.put(word, map.getOrDefault(word, 0) + 1);
        }

/*        List<String> keySetList = new ArrayList<>(map.keySet());
        Collections.sort(keySetList, new Comparator<String>() {
            @Override
            public int compare(String o1, String o2) {
                return o1.compareTo(o2);
            }
        });*/
        PriorityQueue<Diction> que = new PriorityQueue<>(map.size(), (a, b) -> {
            if(b.freq == a.freq){
                return b.str.compareTo(a.str);
            }
            return a.freq - b.freq;
        });
        for (String key : map.keySet()) {
            que.add(new Diction(key, map.get(key)));
            if(que.size() > k) que.poll();
        }
        while (k-- > 0) {
            Diction diction = que.poll();
            answer.add(diction.str);
        }
        Collections.reverse(answer);
        return answer;
    }

    public static void main(String[] args) {
        // write your code here

        String[] words = {"i", "love", "leetcode", "i", "love", "coding"};
        int k = 3;
        List<String> answer = topKFrequent(words, k);
    }
}
