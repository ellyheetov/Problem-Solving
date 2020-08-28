import java.util.*;

class PairNode {
    int index;
    double value;

    PairNode(int index, double value) {
        this.index = index;
        this.value = value;
    }

}
public class Programmers_42889_실패율 {

    public static int[] gameLevel = null;

    public static int[] solution(int N, int[] stages) {

        int[] answer = new int[N];
        gameLevel = new int[N + 2];

        List<PairNode> nodes = new ArrayList<>();
        Arrays.fill(gameLevel, 0);

        for (int stage : stages) {
            recourdRound(stage);
        }

        for (int step = 0; step < N; step++) {
            double percent = calulateFailure(step + 1);
            PairNode temp = new PairNode(step, percent);
            nodes.add(temp);
        }

        nodes.sort(new Comparator<PairNode>() {
            @Override
            public int compare(PairNode o1, PairNode o2) {
                if(o1.value == o2.value)
                    return o1.index - o2.index;
                return -Double.compare(o1.value, o2.value);
            }
        });

        int i = 0;
        for (PairNode node : nodes) {
            answer[i++] = node.index + 1;
        }
        return answer;
    }

    private static double calulateFailure(int currentStage) {
        int total = gameLevel[currentStage];
        int success = gameLevel[currentStage + 1];
        if(total == 0) return 0;
        return (double) (total - success) / (double) total;
    }

    private static void recourdRound(int stage) {
        for (int index = 1; index <= stage; index++) {
            gameLevel[index]++;
        }
    }

    public static void main(String[] args) {
        int N = 5;
        int[] stages = {2, 1, 2, 6, 2, 4, 3, 3};
        int[] answer = solution(N, stages);
        System.out.println(Arrays.toString(answer));
    }
}
