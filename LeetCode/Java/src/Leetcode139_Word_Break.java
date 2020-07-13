import java.util.*;

public class Leetcode139_Word_Break {
    public static boolean wordBreak(String s, List<String> wordDict) {
        Set<String> set = new HashSet<>();

        for (String str : wordDict) set.add(str);

        boolean[] dp = new boolean[s.length() + 1];
        dp[0] = true;

        for(int i =0;i< s.length();i++){
            for(int j = 0;j<=i; j++){
                if(dp[j]==false) continue;
                if(set.contains(s.substring(j,i+1))){
                    dp[i+1] = true;
                    break;
                }
            }
        }
        return dp[s.length()];
    }

    public static void main(String[] args) {
        // write your code here

        String s = "catsandog";
        List<String> wordDict = Arrays.asList("cats", "dog", "sand", "and", "cat");

        boolean answer = wordBreak(s, wordDict);

        System.out.print(answer);
    }
}
