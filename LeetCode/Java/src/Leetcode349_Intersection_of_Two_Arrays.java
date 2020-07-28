import java.lang.reflect.Array;
import java.util.HashSet;

public class Leetcode349_Intersection_of_Two_Arrays {
    public static int[] intersection(int[] nums1, int[] nums2) {
        HashSet<Integer> set = new HashSet<>();
        HashSet<Integer> intersect = new HashSet<>();

        for (int num : nums1) {
            set.add(num);
        }
        for (int num : nums2) {
            if (set.contains(num))
                intersect.add(num);
        }

        int[] answer = new int[intersect.size()];
        int index = 0;
        for (Integer num : intersect) {
            answer[index++] = num;
        }
        return answer;
    }

    public static void main(String[] args) {
        // write your code here
        int[] nums1 = {1, 2, 2};
        int[] nums2 = {2, 2, 3};

        int[] answer = intersection(nums1, nums2);
    }
}
