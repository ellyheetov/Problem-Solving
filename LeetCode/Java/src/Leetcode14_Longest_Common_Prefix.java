import java.util.Arrays;
/*
1. 주어진 문자열 정리하기
2. 주어진 문자열의 길이만큼 반복문 진행
    반복문 내부에서는 주어진 String 개수만큼 비교&확인
3. 더이상 같은 prefix가 아닐 경우 바로 중단
4. 현재까지의 prefix를 return 한다.

Time Complexity: O(NM)
Space Complexity: O(1)
N : size of strings
M : length of string
 */
public class Leetcode14_Longest_Common_Prefix {
    public static String longestCommonPrefix(String[] strs) {

        if (strs.length == 0) return "";
        if (strs.length == 1) return strs[0];

        Arrays.sort(strs);
        int size = strs.length;
        int length = strs[0].length();
        StringBuffer stringBuffer = new StringBuffer();

        for (int i = 0; i < length; i++) {
            int cnt = 0;
            for (int index = 0; index < size - 1; index++) {
                if (strs[index].charAt(i) != strs[index + 1].charAt(i)) break;
                cnt++;
            }
            if (cnt == size - 1)
                stringBuffer.append(strs[0].charAt(i));
            else
                break;
        }
        return stringBuffer.toString();
    }

    public static void main(String[] args) {
        String[] strs = {"ac", "abb"};
        String answer = longestCommonPrefix(strs);
        System.out.print(answer);
    }
}
