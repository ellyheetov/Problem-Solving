public class Leetcode1528_Shuffle_String {
    public static String restoreString(String s, int[] indices) {
        char[] answer = new char[indices.length];

        int index = 0;
        for (int i = 0; i < indices.length; i++) {
            answer[indices[i]] = s.charAt(index++);
        }
        return String.valueOf(answer);
    }

    public static void main(String[] args) {
        String str = "codeleet";
        int[] indices = {4, 5, 6, 7, 0, 2, 1, 3};
        String answer = restoreString(str, indices);
        System.out.print(answer);
    }
}
