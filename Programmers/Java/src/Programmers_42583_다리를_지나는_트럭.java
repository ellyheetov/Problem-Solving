import java.util.LinkedList;
import java.util.Queue;

class TruckObject {
    int weigth;
    int startTime;

    public TruckObject(int weigth, int startTime) {
        this.weigth = weigth;
        this.startTime = startTime;
    }
}

public class Programmers_42583_다리를_지나는_트럭 {
    public static int solution(int bridge_length, int weight, int[] truck_weights) {
        int time = 1;
        int totalWeight = 0;
        int index = 0;

        Queue<TruckObject> truckOnBridge = new LinkedList<>();
        totalWeight += truck_weights[index];
        truckOnBridge.offer(new TruckObject(truck_weights[index++], time));

        while (!truckOnBridge.isEmpty()) {
            //마지막 요소
            if (index == truck_weights.length) {
                time += bridge_length;
                break;
            }
            time++;
            // 다리를 다 건넌 경우 큐에서 제거
            totalWeight -= getOff(truckOnBridge, time, bridge_length);

            //다음 트럭을 실을 수 있는지 검사
            if (totalWeight + truck_weights[index] > weight) continue;

            //실을 수 있는 경우 큐에 추가
            TruckObject nextTruck = new TruckObject(truck_weights[index++], time);
            totalWeight += getOn(nextTruck, truckOnBridge);

        }
        return time;
    }

    private static int getOn(TruckObject nextTruck, Queue<TruckObject> truckOnBridge) {
        truckOnBridge.offer(nextTruck);
        return nextTruck.weigth;
    }

    private static int getOff(Queue<TruckObject> truckOnBridge, int curTime, int bridge_length) {

        int weight = 0;
        int size = truckOnBridge.size();
        while (size-- > 0) {
            if (curTime - truckOnBridge.peek().startTime == bridge_length) {
                weight += truckOnBridge.peek().weigth;
                truckOnBridge.poll();
            } else {
                break;
            }
        }
        return weight;
    }

    public static void main(String[] args) {
        int bridge_length = 100;
        int weight = 100;
        int[] truck_weights = {10,10,10,10,10,10,10,10,10,10};

        int answer = solution(bridge_length, weight, truck_weights);
        System.out.print(answer);
    }
}
