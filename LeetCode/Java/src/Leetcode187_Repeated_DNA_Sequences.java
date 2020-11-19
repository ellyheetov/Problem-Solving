import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;

public class Leetcode187_Repeated_DNA_Sequences {

    public static final int LEN = 10;

    public static List<String> findRepeatedDnaSequences(String s) {

        HashSet<String> set = new HashSet<>();
        HashSet<String> answerSet = new HashSet<>();

        if (s.length() < 10) return new ArrayList<>();

        for (int index = 0; index + LEN <= s.length(); index++) {
            String current = s.substring(index, index + LEN);
            if (set.contains(current))
                answerSet.add(current);
            else set.add(current);
        }

        return new ArrayList<>(answerSet);
    }
/*
    public static List<String> findRepeatedDnaSequences(String s) {

        List<String> answer = new ArrayList<>();
        HashMap<String,Integer> map = new HashMap<>();

        if(s.length() <= 10) return answer;

        for(int index =0; index + LEN <= s.length();index++){
            String current = s.substring(index, index + LEN);
            map.put(current,map.getOrDefault(current,0) + 1);
        }

        map.forEach((key,value) -> {
            if(value > 1) answer.add(key);
        });

        return answer;
    }*/

    public static void main(String[] args) {
        String s = "AAAAAAAAAAA";
        List<String> answer = findRepeatedDnaSequences(s);
        System.out.print(answer);
    }

}
