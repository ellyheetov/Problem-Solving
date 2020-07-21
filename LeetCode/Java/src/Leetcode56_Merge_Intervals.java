import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;

public class Leetcode56_Merge_Intervals {
    public static int[][] merge(int[][] intervals) {

        if (intervals.length < 2) return intervals;

        List<int[]> list = new ArrayList<>();

        Arrays.sort(intervals, Comparator.comparingInt(a -> a[0]));

        int start = intervals[0][0];
        int end = intervals[0][1];

        for (int index = 1; index < intervals.length; index++) {

            if (intervals[index][0] <= end) {
                end = Math.max(intervals[index][1],end);
            } else {
                list.add(new int[]{start, end});
                start = intervals[index][0];
                end = intervals[index][1];
            }
        }
        list.add(new int[]{start, end});
        return list.toArray(new int[0][]);
    }

    public static void main(String[] args) {
        // write your code here
        int[][] intervals = {{1, 4}, {2, 3}};
        int[][] answer = merge(intervals);

        System.out.print(answer.length);
    }
}
