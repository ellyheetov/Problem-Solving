public class Leetcode200_Number_of_Islands {

    public static int boardSize_row;
    public static int boardSize_col;
    public static int[] direction_x = {1, 0, -1, 0};
    public static int[] direction_y = {0, 1, 0, -1};

    public static boolean isBoundary(int x, int y) {
        return x >= 0 && x < boardSize_row && y >= 0 && y < boardSize_col;
    }

    public static void findIsland(int x, int y, char[][] grid) {

        grid[x][y] = '0';

        for (int i = 0; i < 4; i++) {
            int new_x = x + direction_x[i];
            int new_y = y + direction_y[i];
            if (!isBoundary(new_x, new_y)) continue;
            if (grid[new_x][new_y] == '0') continue;
            findIsland(new_x, new_y, grid);
        }
    }

    public static int numIslands(char[][] grid) {

        int cnt = 0;

        if (grid.length == 0) return cnt;

        boardSize_row = grid.length;
        boardSize_col = grid[0].length;

        for (int row = 0; row < boardSize_row; row++) {
            for (int col = 0; col < boardSize_col; col++) {
                if (grid[row][col] == '0') continue;
                findIsland(row, col, grid);
                cnt++;
            }
        }
        return cnt;
    }

    public static void main(String[] args) {
        // write your code here
        char[][] grid = {{'1', '1', '0', '0', '0'},
                {'1', '1', '0', '0', '0'},
                {'0', '0', '1', '0', '0'},
                {'0', '0', '0', '1', '1'}};
        int answer = numIslands(grid);
        System.out.print(answer);
    }
}