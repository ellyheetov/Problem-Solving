public class Programmers_12930_이상한_문자_만들기 {

    // 짝수번째 알파벳은 대문자로, 홀수번째 알파벳은 소문자로 바꾼 문자열을 리턴
    public static String solution(String s) {

        String answer = "";
        String[] stringArray = s.split(" ",-1);

        /*
        * s.split(" ") 로 할경우 오답
        * limit값은 return되는 배열의 크기를 지정한다.
        * s.split(" ", -1) 로 해줌으로써 zero length string도 포함 한다.
        * */

        for(int i =0; i< stringArray.length; i++){
            for(int index = 0; index < stringArray[i].length(); index++){
                if(index%2==0)
                    answer += Character.toUpperCase(stringArray[i].charAt(index));
                else
                    answer += Character.toLowerCase(stringArray[i].charAt(index));
            }
            answer += " ";
        }
        return answer.substring(0,answer.length() -1);
    }
    public static void main(String[] args){
        String s = "try hello world ";
        System.out.print(solution(s));
    }
}
