public class Leetcode64_Minimum_Path_Sum {
    public static int minPathSum(int[][] grid) {

        for(int col = 1; col < grid[0].length; col++){
            grid[0][col] += grid[0][col-1];
        }
        for(int row = 1; row < grid.length; row++){
            grid[row][0] += grid[row-1][0];
        }

        for(int row= 1; row< grid.length; row++){
            for(int col = 1; col < grid[0].length; col++){
                grid[row][col] += Math.min(grid[row-1][col], grid[row][col-1]);
            }
        }
        return grid[grid.length- 1][grid[0].length -1];
    }
    public static void main(String[] args){
        int[][] grid = {{1,2,3},{4,5,6}};
        int answer = minPathSum(grid);
        System.out.print(answer);
    }
}
