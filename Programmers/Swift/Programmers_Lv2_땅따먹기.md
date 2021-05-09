# Programmers Lv2 땅따먹기

- 날짜: 2021/04/02

## 문제
[문제 링크](https://programmers.co.kr/learn/courses/30/lessons/12913)

## Code
```swift
func solution(_ land:[[Int]]) -> Int{
    
    var land = land
    for row in 1..<land.count {
        land[row][0] = land[row][0] + max(land[row-1][1], land[row-1][2], land[row-1][3])
        land[row][1] = land[row][1] + max(land[row-1][0], land[row-1][2], land[row-1][3])
        land[row][2] = land[row][2] + max(land[row-1][0], land[row-1][1], land[row-1][3])
        land[row][3] = land[row][3] + max(land[row-1][0], land[row-1][1], land[row-1][2])
    }
    return land[land.count-1].max()!
}

```

## Complexity
N : 행의 개수

모든 행에 대해서 윗 행과 비교하는 작업이 일어난다. 모든 행을 순회하는데 O(N)의 복잡도를 가지며, 윗 행에서 최대 값을 찾는데에서 max함수를 이용한다.
현재 max에서 비교하는 값은 3개이므로, O(N)의 복잡도가 아닌 O(1)의 복잡도를 가진다.
따라서 이 문제의 시간복잡도는 **O(N)** 이다. 

## Max 함수
- `max()` : O(N) (N: 비교하는 원소의 개수)

max 함수는 가지고있는 요소들을 모두 확인해야하므로 복잡도 O(N)을 갖는다.
