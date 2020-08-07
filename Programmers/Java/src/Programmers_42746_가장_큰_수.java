import java.util.Arrays;
import java.util.Comparator;

public class Programmers_42746_가장_큰_수 {

    public static String solution(int[] numbers) {
        String answer = "";

        String[] strArray = new String[numbers.length];

        for(int index = 0; index < numbers.length; ++index){
            strArray[index] = Integer.toString(numbers[index]);
        }

        Arrays.sort(strArray, new Comparator<String>() {
            @Override
            public int compare(String o1, String o2) {
                return (o2+o1).compareTo(o1+o2);
            }
        });

        if(strArray[0].equals("0")) return "0";

        for(int index = 0;index< strArray.length;index++){
            answer += strArray[index];
        }
        return answer;
    }
    public static void main(String[] args){
        int[] numbers = {0,0};
        String answer = solution(numbers);
        System.out.print(answer);
    }
}
