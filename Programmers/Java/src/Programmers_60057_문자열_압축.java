import java.util.ArrayList;
import java.util.List;

public class Programmers_60057_문자열_압축 {


    public static int solution(String s) {

        int answer = s.length();

        for (int size = 1; size <= s.length() / 2; size++) {
            int result = findLength(s, size);
            answer = Math.min(result, answer);
        }
        return answer;
    }

    private static int findLength(String s, int size) {

        String result = "";

        List<String> words = wordsSplit(s, size);

        int exist = s.length() % size;
        int cnt = 1;

        for (int index = 0; index < words.size() - 1; index++) {
            if (words.get(index).equals(words.get(index + 1))) {
                cnt++;
                continue;
            }
            if (cnt > 1) result += String.valueOf(cnt) + words.get(index);
            else result += words.get(index);

            cnt = 1;
        }
        if (cnt > 1) result += String.valueOf(cnt) + words.get(words.size() - 1);
        else result += words.get(words.size() - 1);

        return result.length() + exist;
    }

    private static List<String> wordsSplit(String s, int size) {
        List<String> words = new ArrayList<String>();

        for (int i = 0; i <= s.length() - size; i += size) {
            words.add(s.substring(i, i + size));
        }
        return words;
    }

    public static void main(String[] args) {
        String str = "abcabcdede";
        int answer = solution(str);
        System.out.print(answer);
    }

}
