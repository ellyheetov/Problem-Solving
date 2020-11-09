import java.util.HashMap;

/*
문제) 주어진 배열에서 distinct한 원소를 K개 가질 수 있는 부분집합의 개수 구하기

접근) Sliding Window
풀이)
left와 right index를 가지고 있다.
right index를 증가시키면서 window의 길이를 확장시킨다.
distinct한 원소의 갯수가 K개가 될 경우 count값을 증가시키고
left index의 값을 증가시키면서 window의 길이를 줄인다.

그런데 이와 같은 풀이법에는 문제점이 존재한다.

{1,2,1,2}의 경우
{1,2}, {1,2,1}, {1,2,1,2}, {2,1,2}, {1,2} 5개의 부분집합을 뽑아 낼 수 있다.
하지만, {2,1}을 포함하지 못한다는 한계를 가진다.

이를 해결하기 위해서는 2개의 window를 사용 해야 한다.
2개의 window를 가지고

distinct한 원소가 K개를 초과 할 경우 윈도우1의 사이즈를 줄여가며
더 이상 만족하지 못하는 위치의 index를 반환한다 => left1 index
ㅜ
distinct한 원소가 K개와 같은 경우 윈도우2의 사이즈를 줄여가며
더 이상 만족하지 못하는 위치의 index를 반환한다 => left2 index

두 index의 차가 범위 내에서 distinct한 원소 K개를 만족하는 부분 집합의 개수이다.

하지만, 잘 모르겠다..ㅜㅜ

Time Complexity: O(N)
Space Complexity: O(N)

 */
public class Leetcode992_Subarrays_with_K_Different_Integers {
    public static int subarraysWithKDistinct(int[] A, int K) {

        int left1 = 0, left2 = 0, right = 0;
        HashMap<Integer, Integer> window1 = new HashMap(); // number, count
        HashMap<Integer, Integer> window2 = new HashMap(); // number, count
        int cnt = 0;

        while (right < A.length) {

            window1.put(A[right], window1.getOrDefault(A[right], 0) + 1);
            window2.put(A[right], window2.getOrDefault(A[right], 0) + 1);
            right++;

            while (window1.size() > K) {
                window1.computeIfPresent(A[left1], (key, value) -> --value);
                if(window1.get(A[left1]) == 0)
                    window1.remove(A[left1]);
                left1++;
            }
            while (window2.size() >= K) {
                window2.computeIfPresent(A[left2], (key, value) -> --value);
                if(window2.get(A[left2]) == 0)
                    window2.remove(A[left2]);
                left2++;
            }
            cnt += left2 - left1;
        }
        return cnt;
    }

    public static void main(String[] args) {
        // write your code here
        int[] A = {1, 2, 1, 2, 3};
        int K = 2;
        int answer = subarraysWithKDistinct(A, K);
        System.out.print(answer);
    }

    /*
    public int subarraysWithKDistinct(int[] A, int K) {
       int left = 0, right = 0;
        HashMap<Integer, Integer> map = new HashMap(); // number, count
        int cnt = 0;

        while (right < A.length) {

            while (map.size() == K) {
                cnt++;
                if(map.containsKey(A[right])) break;
                map.computeIfPresent(A[left], (key, value) -> --value);
                if (map.get(A[left]) == 0) map.remove(A[left]);
                left++;
            }

            map.put(A[right], map.computeIfAbsent(A[right], value -> 0) + 1);
            right++;
        }
        return cnt;
    }
     */
}
