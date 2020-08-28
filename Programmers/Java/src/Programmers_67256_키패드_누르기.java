public class Programmers_67256_키패드_누르기 {

    public static String[][] keypad = {{"1", "2", "3"}, {"4", "5", "6"}, {"7", "8", "9"}, {"*", "0", "#"}};

    public static String solution(int[] numbers, String hand) {
        String answer = "";

        int[] currentLeftHand = {3,0};
        int[] currentRightHand = {3,2};

        for(int index = 0; index < numbers.length; index++){
            int[] destination = numberToPlace(String.valueOf(numbers[index]));

            if(destination[1] == 0){
                currentLeftHand = destination;
                answer +="L";
                continue;
            }
            if(destination[1] == 2){
                currentRightHand = destination;
                answer +="R";
                continue;
            }
            int leftdiffer = howManyDifferent(currentLeftHand,destination);
            int rightdiffer = howManyDifferent(currentRightHand,destination);

            if(leftdiffer < rightdiffer){
                currentLeftHand = destination;
                answer +="L";
            }
            else if(leftdiffer > rightdiffer){
                currentRightHand = destination;
                answer +="R";
            }
            else {
                if(hand.equals("right")) {
                    currentRightHand = destination;
                    answer +="R";
                }
                else {
                    currentLeftHand = destination;
                    answer +="L";
                }
            }
        }
        return answer;
    }

    public static int howManyDifferent(int[] hand, int[] destination){
        return Math.abs(hand[0] - destination[0]) + Math.abs(hand[1] - destination[1]);
    }
    public static int[] numberToPlace(String target){
        for(int i = 0; i< 4; i++){
            for(int j =0; j< 3; j++){
                if(target.equals(keypad[i][j]))
                    return new int[] {i,j};
            }
        }
        return null;
    }
    public static void main(String[] args) {
        int[] numbers = {7, 0, 8, 2, 8, 3, 1, 5, 7, 6, 2};
        String hand = "left";
        String pattern = "LRLLRRLLLRR";
        String answer = solution(numbers, hand);

        System.out.println(pattern);
        System.out.println(answer);
        System.out.print(answer.equals(pattern));
    }
}
