import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.stream.IntStream;

public class BJ_11656_접미사_배열 {

    public static void main(String[] args) throws IOException {
        // write your code here
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        String input = bufferedReader.readLine();

        IntStream.range(0,input.length())
                .boxed()
                .map(input::substring)
                .sorted()
                .forEach(System.out::println);
    }
}
