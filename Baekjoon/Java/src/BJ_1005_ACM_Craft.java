import java.util.*;

/*

@문제
건물을 짓는데에는 순서가 존재한다. 건물을 완성할 수 있는 최단시간을 구하는 문제이다.

@잘못된 접근방법
단순한 DP로 접근하였다.

dp : 정점에 도달하기 위하여 걸리는 시간 + 해당 정점에서 걸리는 시간
time: 해당 정점에서 걸리는 시간

진입차수가 0 이상 인 것들은 dp값을 확인하고
진입차수가 0인 것들은 time값을 확인하려고 했다.

그런데 이것의 문제점은 각 정점간의 간선이 주어지는 순서에 따라서 dp의 값이 달라진다는 것이다.

각각의 정점간의 순서가 정해 져 있기 떄문에 큐로 접근해야 한다.

@Solution
진입차수가 0인 정점을 먼저 큐에 삽입하고,
해당 정점에서 뻗어나갈 수 있는 다음 정점들을 찾는다.
이때, 간선을 제거하며 진입차수가 0이 되었을 경우 다음 정점을 큐에 삽입한다.
큐가 빌때까지 이와 같은 과정을 반복한다.

만약, 모든 정점을 방문하기 전에 큐가 빈다면 이는 사이클이 존재함을 의미한다.
모든 정점을 방문했다면 큐에서 꺼낸 순서가 위상 정렬의 결과이다.

@Time Complexity
O(V+E)

@Space Complexity
O(V+E)

 */
public class BJ_1005_ACM_Craft {
    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);
        int testCase = scanner.nextInt();

        while (testCase-- > 0) {
            int tower = scanner.nextInt();
            int sizeOfRule = scanner.nextInt();

            int[] time = new int[tower + 1];
            int[] in = new int[time.length];

            LinkedList<Integer>[] arrayList = new LinkedList[time.length];
            for (int i = 0; i < time.length; i++) {
                arrayList[i] = new LinkedList<>();
            }

            for (int i = 0; i < tower; i++) {
                time[i + 1] = scanner.nextInt();
            }
            for (int i = 0; i < sizeOfRule; i++) {
                int from = scanner.nextInt();
                int to = scanner.nextInt();

                arrayList[from].add(to);
                in[to]++;
            }
            int k = scanner.nextInt();
            int answer = solution(time, arrayList, in, k);
            printAnswer(answer);
        }
        scanner.close();
    }

    private static int solution(int[] time, LinkedList<Integer>[] arrayList, int[] in, int k) {

        int[] dp = new int[time.length];

        Queue<Integer> que = new LinkedList<>();
        for (int index = 1; index < arrayList.length; index++) {
            if (in[index] == 0) {
                que.offer(index); // 진입 차수가 0인 정점을 큐에 삽입한다.
                dp[index] = time[index];
            }
        }

        while (!que.isEmpty()) {
            int from = que.poll();

            for (int to : arrayList[from]) {
                dp[to] = Math.max(dp[to], time[to] + dp[from]);

                if(--in[to] == 0) // 연결된 간선을 제거
                    que.offer(to); // 진입차수가 0 이 되었을때 큐에 삽입
            }
        }
        return dp[k];
    }

    private static void printAnswer(int answer) {
        System.out.println(answer);
    }
}
/*
1
3 2
1 2 3
3 2
2 1
1
 */
/*
1
8 8
10 20 1 5 8 7 1 43
1 2
1 3
2 4
2 5
3 6
5 7
6 7
7 8
7
 */