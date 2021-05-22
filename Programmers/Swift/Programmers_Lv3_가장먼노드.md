# Programmers Lv2 가장 먼 노드

- 날짜: 2021/05/22
- 문제 유형 : 그래프

## 문제
[문제 링크](https://programmers.co.kr/learn/courses/30/lessons/49189)

## Code
```swift
func solution_PRO_49189_가장먼노드(_ n:Int, _ edge:[[Int]]) -> Int {
    typealias Weight = (index: Int, count : Int)
    var info = [Int](repeating: Int.max, count: n + 1)
    var graph = [[Int]](repeating: [Int](), count: n+1)
    var que = [Weight]()
    
    for value in edge {
        graph[value[0]].append(value[1])
        graph[value[1]].append(value[0])
    }
    info[0] = 0
    info[1] = 1
    que.append((1,1))
    
    while(!que.isEmpty){
        let current = que.removeFirst()
        for next in graph[current.index] where info[next] > current.count + 1 {
            info[next] = current.count + 1
            que.append((next,current.count+1))
        }
    }
    let maxLen = info.max()
    let answer = info.filter{ $0 == maxLen }.count
    return answer
}

```

## Complexity

<img width="350" alt="Screen Shot 2021-05-22 at 4 24 54 PM" src="https://user-images.githubusercontent.com/60229909/119218216-3eacfc00-bb1a-11eb-99d5-c2b5305875ad.png">

인접한 노드들을 순차적으로 탐색하는 BFS 방식  
이미 방문한 노드를 재 방문 하지 않도록 info 배열에 count를 저장(memoization)

시간 복잡도는 **O(N)** (N:간선의 수)