public class Leetcode1143_Longest_Common_Subsequence {

    public static int longestCommonSubsequence(String text1, String text2) {

        int[][] board = new int[text2.length() + 1][text1.length() + 1];

        for(int i = 1; i<= text2.length();i++){
            for(int j = 1;j<= text1.length();j++){
                if(text2.charAt(i-1)== text1.charAt(j-1)) {
                    board[i][j] = board[i-1][j-1] +1;
                } else
                    board[i][j] = Math.max(board[i-1][j], board[i][j-1]);
            }
        }
        return board[text2.length()][text1.length()];
    }

    public static void main(String[] args) {
        // write your code here
        String text1 = "abcde";
        String text2 = "ace";

        int answer = longestCommonSubsequence(text1, text2);
        System.out.print(answer);
    }
}
