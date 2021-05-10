# Programmers Lv2 기능개발

- 날짜: 2021/05/10
- 문제 유형 : Stack/Queue

## 문제
[문제 링크](https://programmers.co.kr/learn/courses/30/lessons/42586)

## Code

1. Solution - queue를 이용
```swift
func solution_PRO_42586_기능개발(_ progresses:[Int], _ speeds:[Int]) -> [Int] {
    let FINISH : Int = 100
    
    var remain = [Int](repeating: 0, count: progresses.count) // 더 일해야하는 날짜를 계산하여 저장
    
    for (index, progress) in progresses.enumerated() {
        var date : Int = (FINISH - progress) / speeds[index]
        if (FINISH - progress) % speeds[index] != 0 {
            date += 1
        }
        remain[index] = date
    }
    
    var que = [Int]()
    var answer = [Int]()
    
    for date in remain {
        if  que.isEmpty || que.first! >= date {
            que.append(date)
            continue
        }
        answer.append(que.count)
        que.removeAll()
        que.append(date)
    }
    if !que.isEmpty {
        answer.append(que.count)
    }
    return answer
}
```

## Complexity

N : progresses 배열의 크기
- `append()` : O(1)
- `removeAll()` : O(N)

progresses의 작업들이 배포되기 위해서 며칠이 걸리는지 계산하는데에 O(N)이 소요된다.

또한, 배포 날 몇개의 배포가 이루어지는지 답을 도출하기 위해서 또 한번 순회 O(N)가 필요하다.

이때, 순회하면서 작업을 Queue에 넣는데에 O(1), 모두 빼내는데에 O(N)이 소요 된다. 따라서 최악의 경우, **O(N^2)** 의 시간 복잡도를 갖게 된다. 


## Code

2. Solution - count 변수 이용
```swift

func solution_PRO_42586_기능개발(_ progresses:[Int], _ speeds:[Int]) -> [Int] {
    let FINISH : Int = 100
    
    var remain = [Int](repeating: 0, count: progresses.count) // 더 일해야하는 날짜를 계산하여 저장
    
    for (index, progress) in progresses.enumerated() {
        var date : Int = (FINISH - progress) / speeds[index]
        if (FINISH - progress) % speeds[index] != 0 {
            date += 1
        }
        remain[index] = date
    }
    
    var last = remain[0]
    var count = 0
    var answer = [Int]()
    
    for date in remain {
        if last >= date {
            count += 1
            continue
        }
        answer.append(count)
        count = 1
        last = date
    }
    if count != 0 {
        answer.append(count)
    }
    return answer
}

```
## Complexity
N : progresses 배열의 크기


progresses의 작업들이 배포되기 위해서 며칠이 걸리는지 계산하는데에 O(N)이 소요된다. 또한, 배포 날 몇개의 배포가 이루어지는지 답을 도출하기 위해서 또 한번 순회 O(N)가 필요하다.
결과적으로 **O(N)** 의 시간 복잡도를 갖는다.


## Complexity 비교

removeAll()은 매번 호출되지 않으므로 프로그래머스 채점시에는 2가지 Solution code에 대해 거의 동일한 시간이 소요된다.

<img width="384" alt="Screen Shot 2021-05-10 at 2 15 01 PM" src="https://user-images.githubusercontent.com/60229909/117608992-1d532400-b19a-11eb-8cfb-d259ee2cde75.png">
<img width="384" alt="Screen Shot 2021-05-10 at 2 16 21 PM" src="https://user-images.githubusercontent.com/60229909/117609084-4d9ac280-b19a-11eb-8f21-a14ca3f25f09.png">


## 추가

좌측에 있는 연산이 먼저 일어나기 때문에, queue가 비어있는지 확인하기 전에 값을 빼려고하면 에러가 발생한다.
```swift
if  que.first! >= date || que.isEmpty{

}
```
하지만 이와같이 비어있는지 먼저 확인하고, 값을 뺴는 경우 정상작동한다. 
```swift
if  que.isEmpty || que.first! >= date {

}
```