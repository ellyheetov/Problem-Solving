public class Programmers_12948_핸드폰_번호_가리기 {

    public static String solution(String phone_number) {
        StringBuilder answer = new StringBuilder();

        int size = phone_number.length();

        for(int i =0; i< size - 4; i++){
            answer.append("*");
        }
        for(int i = size -4; i< size; i++){
            answer.append(phone_number.charAt(i));
        }
        return answer.toString();
    }
    /* 정규식을 이용한 풀이
    public static String solution(String phone_number) {
        return phone_number.replaceAll(".(?=.{4})", "*");
    }
     */
    public static void main(String[] args){
        String phone_number = "027778888";
        String answer = solution(phone_number);
        System.out.print(answer);
    }
}
