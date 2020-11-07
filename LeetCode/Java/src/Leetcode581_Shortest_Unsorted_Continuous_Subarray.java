import java.util.Stack;

/*
문제 : 오름차순으로 정렬된 배열을 얻기 위해서 정렬이 필요한 부분의 길이를 구한다.

Index와 Stack을 활용하여 문제 풀이

Step 1. 정렬이 필요한 시작 index 구하기
주어진 배열의 앞에서부터 탐색한다.
증가 하는 값일 경우 stack에 넣는다.
증가 하지 않는 값일 경우 stack에 있는 값과 비교하여 조건이 맞을 때까지 stack에서 pop한다.

Step 2. 정렬이 필요한 마지막 index 구하기
주어진 배열의 뒤에서부터 탐색한다.
감소하는 값일 경우 stack에 넣는다.
증가하는 경우에는 stack에 있는 값과 비교하여 조건이 맞을 때까지 stack에서 pop한다.

Step 3. 길이를 반환

Time Complexity: O(N)
Space Complexity: O(N)
 */

public class Leetcode581_Shortest_Unsorted_Continuous_Subarray {
    public static int findUnsortedSubarray(int[] nums) {
        Stack<Integer> stack = new Stack<>();

        int start = nums.length;
        int last = 0;

        for (int index = 0; index < nums.length; index++) {
            while (!stack.isEmpty() && nums[stack.peek()] > nums[index])
                start = Math.min(start, stack.pop());
            stack.push(index);
        }
        stack.clear();

        for (int index = nums.length - 1; index >= 0; index--) {
            while (!stack.isEmpty() && nums[stack.peek()] < nums[index]) {
                last = Math.max(last, stack.pop());
            }
            stack.push(index);
        }

        return last - start > 0 ? last - start + 1 : 0;
    }

    public static void main(String[] args) {
        int[] nums = {2, 6, 4, 8, 15, 9, 10};
        int answer = findUnsortedSubarray(nums);
        System.out.print(answer);
    }
}
