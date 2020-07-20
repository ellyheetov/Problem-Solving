import javax.swing.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Leetcode57_Insert_Interval {


    public static int[][] insert(int[][] intervals, int[] newInterval) {
        List<int[]> inserted = new ArrayList<>();

        int index = 0;
        while(index < intervals.length && intervals[index][1] < newInterval[0]){
            inserted.add(intervals[index++]);
        }
        while(index < intervals.length && intervals[index][0] <= newInterval[1]){
            newInterval[0] = Math.min(newInterval[0], intervals[index][0]);
            newInterval[1] = Math.max(newInterval[1], intervals[index][1]);
            index++;
        }
        inserted.add(newInterval);

        while(index < intervals.length){
            inserted.add(intervals[index++]);
        }
        return inserted.toArray(new int[0][]);
    }

    public static void main(String[] args) {
        // write your code here

        int[][] intervals = {{1, 3}, {6, 9}};
        int[] newInterval = {2, 5};

        int[][] answer = insert(intervals, newInterval);

        System.out.print(answer.length);
    }
}
