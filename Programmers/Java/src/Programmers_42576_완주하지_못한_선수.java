import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

public class Programmers_42576_완주하지_못한_선수 {

    public static String solution(String[] participants, String[] completions) {
        Map<String, Integer> player = new HashMap<>();

        for (String participant : participants) {
            player.put(participant, player.getOrDefault(participant, 0) + 1);
        }

        for (String completion : completions) {
            player.put(completion, player.get(completion) - 1);
        }
        /*for (String key : player.keySet()) {
            if (player.get(key) != 0)
                return key;
        }*/
        for (Map.Entry<String,Integer> entry : player.entrySet()){
            if(entry.getValue() != 0)
                return entry.getKey();
        }
        return "";
    }

    /*public static String solution(String[] participants, String[] completions) {
        Arrays.sort(participants);
        Arrays.sort(completions);

        for(int index = 0; index< completions.length; index++){
            if(!participants[index].equals(completions[index]))
                return participants[index];
        }
        return participants[participants.length-1];
    }*/


    public static void main(String[] args) {
        String[] participant = {"mislav", "stanko", "mislav", "ana"};
        String[] completion = {"stanko", "ana", "mislav"};

        String answer = solution(participant, completion);
        System.out.print(answer);
    }
}
