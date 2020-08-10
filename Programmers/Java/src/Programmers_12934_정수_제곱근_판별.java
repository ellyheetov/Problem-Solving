public class Programmers_12934_정수_제곱근_판별 {
    public static long solution(long n) {
        long squareRoot = (long) Math.sqrt(n);

        if(squareRoot * squareRoot == n){
            return (squareRoot + 1)*(squareRoot + 1);
        }
        else
            return -1;
    }
    public static void main(String[] args){
        long n = 121;
        long answer = solution(n);
        System.out.print(answer);
    }
}
