import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BJ_11724_연결_요소의_개수 {

    public static int[] parent = null;

    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        st = new StringTokenizer(bufferedReader.readLine());
        int n = Integer.parseInt(st.nextToken());
        int link = Integer.parseInt(st.nextToken());

        int[][] connect = new int[link][2];
        for (int i = 0; i < link; i++) {
            st = new StringTokenizer(bufferedReader.readLine());
            connect[i][0] = Integer.parseInt(st.nextToken());
            connect[i][1] = Integer.parseInt(st.nextToken());
        }
        solution(n, connect);
    }

    private static void solution(int n, int[][] connect) {
        int cnt = 0;
        parent = new int[n + 1];
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }

        for (int i = 0; i < connect.length; i++) {
            int x = connect[i][0];
            int y = connect[i][1];

            merge(x, y);
        }
        for (int i = 1; i <= n; i++) {
            if (parent[i] == i) cnt++;
        }
        System.out.print(cnt);
    }

    private static void merge(int x, int y) {
        if (x > y) mySwap(x, y);

        y = find(y);
        x = find(x);
        parent[y] = x;
    }

    private static int find(int x) {
        if (parent[x] == x) return x;
        return x = find(parent[x]);
    }

    private static void mySwap(int x, int y) {
        int temp = y;
        y = x;
        x = temp;
    }
}
