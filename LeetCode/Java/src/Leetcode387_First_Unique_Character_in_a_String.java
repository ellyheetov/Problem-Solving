import java.util.Arrays;
import java.util.HashMap;

public class Leetcode387_First_Unique_Character_in_a_String {
    public static int firstUniqChar(String s) {
        int[] count = new int[26];

        for(int i =0;i< s.length();i++){
            char c = s.charAt(i);
            count[c-'a']++;
        }
        for(int i =0;i< s.length(); i++){
            char c = s.charAt(i);
            if(count[c-'a'] == 1) return i;
        }
        return -1;
    }
    /*public static int firstUniqChar(String s) {
        HashMap<Character, Integer> map = new HashMap<Character, Integer>();

        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);

            map.put(c, map.getOrDefault(c, 0) + 1);
        }
        for (int i = 0; i < s.length(); i++) {
            if(map.get(s.charAt(i)) == 1)
                return i;
        }
        return -1;
    }*/

    public static void main(String[] args) {
        // write your code here
        String str = "leetcode";
        int answer = firstUniqChar(str);
        System.out.print(answer);
    }
}
