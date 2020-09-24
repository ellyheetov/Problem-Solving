import java.util.Arrays;

public class Programmers_42898_등굣길 {
    public static final int OBSTACLE = -1;

    public static int solution(int col, int row, int[][] puddles) {
        int[][] street = new int[row][col];

        for (int i = 0; i < puddles.length; i++) {
            street[puddles[i][0]][puddles[i][1]] = OBSTACLE;
        }
        street[0][0] = 1;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if(street[i][j] == OBSTACLE){
                    street[i][j] = 0;
                    continue;
                }

                if(i !=0){
                    street[i][j] += (street[i-1][j]) % 1000000007;
                }
                if(j!=0){
                    street[i][j] += (street[i][j-1]) % 1000000007;
                }
            }
        }
        return street[row -1][col -1] % 1000000007;
    }

    public static void main(String[] args) {
        int m = 4, n = 3;
        int[][] puddles = {{2, 2}};
        int answer = solution(m, n, puddles);
        System.out.print(answer);
    }
}

