import java.util.ArrayList;
import java.util.List;

public class Leetcode39_Combination_Sum {
    public static List<List<Integer>> combinationSum(int[] candidates, int target) {

        List<List<Integer>> answer = new ArrayList<List<Integer>>();
        combine(answer, new ArrayList<Integer>(), candidates, 0, 0, target);
        return answer;
    }

    private static void combine(List<List<Integer>> answer, ArrayList<Integer> array, int[] candidates, int startIndex, int sum, int target) {
        if (sum == target) {
            answer.add(new ArrayList<>(array));
            return;
        }
        if(sum > target) return;

        for (int index = startIndex; index < candidates.length; index++) {
            array.add(candidates[index]);
            sum += candidates[index];
            combine(answer, array, candidates, index, sum, target);
            array.remove(array.size() -1);
            sum -=candidates[index];
        }
    }

    public static void main(String[] args) {
        // write your code here
        int[] candidate = {2, 3, 6, 7};
        List<List<Integer>> answer = combinationSum(candidate, 7);
    }
}
