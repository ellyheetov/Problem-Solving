public class Programmers_42860_조이스틱 {


    public static int solution(String name) {
        int answer = 0;

        int right = 0;
        int left = name.length() - 1;
        int direction = 0;

        for (int index = 0; index < name.length(); ++index) {
            int temp = name.charAt(index) - 'A';
            answer += Math.min(26 - temp, temp);

            if (temp != 0) right = index;
        }
        for (int index = name.length() - 1; index > 0; --index) {
            if (name.charAt(index) != 'A')
                left = index;
        }

        direction = Math.min(name.length() - left, right);
        answer += direction;
        return answer;
    }


    public static void main(String[] args) {
        String name = "ABABAAAAAAABA";
        int answer = solution(name);
        System.out.print(answer);
    }
}
