import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;

public class Leetcode435_Nonoverlapping_Intervals {

    public static int eraseOverlapIntervals(int[][] intervals) {
        if (intervals.length < 2) return 0;

        Arrays.sort(intervals, Comparator.comparing(a -> a[0]));
        List<int[]> list = new ArrayList<>();

        int cnt = 1;
        int end = intervals[0][1];

        for (int index = 1; index < intervals.length; index++) {
            if (intervals[index][0] >= end) {
                end = intervals[index][1];
                cnt++;
            }
        }
        return intervals.length - cnt;
    }

    public static void main(String[] args) {
        // write your code here
        int[][] intervals = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
        int answer = eraseOverlapIntervals(intervals);

        System.out.print(answer);
    }
}
