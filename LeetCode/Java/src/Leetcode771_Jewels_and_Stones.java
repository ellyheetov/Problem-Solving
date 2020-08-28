import java.util.HashSet;
import java.util.Set;

public class Leetcode771_Jewels_and_Stones {

    public static int numJewelsInStones(String J, String S) {
        int answer = 0;

        Set<Character> set = new HashSet<>();
        for(int index = 0;index< J.length(); index++){
            set.add(J.charAt(index));
        }

        for(int i = 0;i< S.length(); i++){
            if(set.contains(S.charAt(i)))
                answer++;
        }
        return answer;
    }
    public static void main(String[] args) {
        // write your code here
        String J = "ZZ";
        String S = "zz";
        int answer = numJewelsInStones(J,S);
        System.out.print(answer);
    }
}
