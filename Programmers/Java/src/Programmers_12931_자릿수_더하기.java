public class Programmers_12931_자릿수_더하기 {

    public static int solution(int n) {
        int answer = 0;

        String str = Integer.toString(n);

        for(int i=0;i< str.length();i++){
            answer += Integer.parseInt(String.valueOf(str.charAt(i)));
        }
        return answer;
    }
    public static void main(String[] args){
        int n = 987;
        int answer = solution(n);
        System.out.print(answer);
    }
}
