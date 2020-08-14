import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

public class Leetcode77_Combinations {

    public static List<List<Integer>> combine(int n, int k) {

        List<List<Integer>> answer = new ArrayList<List<Integer>>();

        combine(answer, new ArrayList<Integer>(), 1,n,k);
        return answer;
    }

    private static void combine(List<List<Integer>> answer, ArrayList<Integer> combining, int start, int n, int k) {
        if(k == 0){
            answer.add(new ArrayList<Integer>(combining));
            return;
        }
        for(int i = start; i <= n; i++){
            combining.add(i);
            combine(answer,combining,i+1,n,k-1);
            combining.remove(combining.size() -1);
        }
    }

    public static void main(String[] args) {
        // write your code here
        List<List<Integer>> answer = combine(4, 2);
    }
}
