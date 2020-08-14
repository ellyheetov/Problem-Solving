import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Leetcode40_Combination_Sum_II {

    public static List<List<Integer>> combinationSum2(int[] candidates, int target) {
        Arrays.sort(candidates);
        List<List<Integer>> answer = new ArrayList<List<Integer>>();
        combination(answer, new ArrayList<>(), candidates, 0, 0, target);
        return answer;
    }

    private static void combination(List<List<Integer>> answer, ArrayList<Integer> array, int[] candidates, int startIndex, int sum, int target) {

        if (sum > target) return;

        if (sum == target) {
            answer.add(new ArrayList<>(array));
            return;
        }
//        sum < target)
        for (int index = startIndex; index < candidates.length; index++) {

            array.add(candidates[index]);
            sum += candidates[index];
            combination(answer, array, candidates, index + 1, sum, target);
            sum -= candidates[index];
            array.remove(array.size() - 1);
            while (index < candidates.length - 1 && candidates[index] == candidates[index + 1])
                index++;
        }

    }

    public static void main(String[] args) {
        // write your code here

        int[] candidates = {10, 1, 2, 7, 6, 1, 5};
        int target = 8;
        List<List<Integer>> answer = combinationSum2(candidates, target);
    }
}
