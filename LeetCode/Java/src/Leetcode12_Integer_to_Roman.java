public class Leetcode12_Integer_to_Roman {

    static int[] digit = new int[]{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    static String[] roman = new String[]{"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    public static String intToRoman(int num) {
        return getConversion(num);
    }

    private static String getConversion(int num) {
        if (num == 0) return "";

        int index;
        index = getDiversor(num);
        return roman[index] + getConversion(num - digit[index]);
    }

    private static int getDiversor(int num) {
        for (int index = 0; index < digit.length; index++) {
            if (num / digit[index] > 0) return index;
        }
        return -1;
    }

    public static void main(String[] args) {
        int num = 490;
        String answer = intToRoman(num);
        System.out.print(answer);
    }
}
