import java.util.*;
/*
Time Complexity: O(NlogN)
Space Complexity: O(N)
 */
public class BJ_7785_회사에_있는_사람 {

    public static Set<String> persons = new HashSet<String>();

    public static void main(String[] args) {
        // write your code here
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();

        while(t-->0)
        {
            String name = scanner.next();
            String action = scanner.next();
            enterOrLeave(name,action);
        }

        ArrayList<String> answer = new ArrayList<>(persons); //생성과 동시에 초기화
        answer.sort((a,b)->b.compareTo(a)); //ArrayList 사전 역순으로 정렬

        answer.forEach(System.out::println);
    }

    private static void enterOrLeave(String name, String action) {
        if(action.equals("enter"))
            persons.add(name);
        else
            persons.remove(name);
    }
}
