import java.util.Arrays;

public class Programmers_42747_H_Index {
    public static int solution(int[] citations) {

        Arrays.sort(citations);

        int size = citations.length;

        for (int index = 0; index < citations.length; index++) {
            int current = citations[size - index - 1];
            if(current <= index) return index;
        }
        return 0;
    }

    public static void main(String[] args) {
        int[] citatioins = {10,11,12,13};
        int answer = solution(citatioins);
        System.out.print(answer);
    }
}

