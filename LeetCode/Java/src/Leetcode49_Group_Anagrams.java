import java.util.*;

public class Leetcode49_Group_Anagrams {

    public static List<List<String>> groupAnagrams(String[] strs) {

        if(strs.length == 0 ) return new ArrayList<>();

        Map<String,List> map = new HashMap<String,List>();

        for(String str : strs){
            char[] charArray = str.toCharArray();
            Arrays.sort(charArray);

            String key = String.valueOf(charArray);

            if(!map.containsKey(key)){
                map.put(key,new ArrayList());
            }
            map.get(key).add(str);
        }
        return new ArrayList(map.values());
    }

    public static void main(String[] args) {
        // write your code here

        String[] strs = { "eat", "tea", "tan", "ate", "nat", "bat"};
        List<List<String>> answer = groupAnagrams(strs);
    }
}
