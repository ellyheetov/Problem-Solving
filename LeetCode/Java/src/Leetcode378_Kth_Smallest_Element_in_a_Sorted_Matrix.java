import java.util.*;

public class Leetcode378_Kth_Smallest_Element_in_a_Sorted_Matrix {

    //List를 사용한 풀이
    /*
    public static int kthSmallest(int[][] matrix, int k) {

        int size = matrix.length;

        List<Integer> list = new ArrayList<>();

        for(int i = 0; i< size; i++){
            for(int j = 0; j< size; j++){
                list.add(matrix[i][j]);
            }
        }
        Collections.sort(list);
        return list.get(k -1);
    }
    */

    //int array를 사용한 풀이
    public static int kthSmallest(int[][] matrix, int k) {

        int size = matrix.length;

        int[] list = new int[size*size];

        int count = 0;
        for(int i = 0; i< size; i++){
            for(int j = 0; j< size; j++){
                list[count++] = matrix[i][j];
            }
        }
        Arrays.sort(list);
        return list[k-1];
    }

    public static void main(String[] args){
        int[][] matrix = {{1,5,9},{10,11,13},{12,13,15}};
        int k = 8;
        int answer = kthSmallest(matrix,k);
        System.out.print(answer);
    }
}

