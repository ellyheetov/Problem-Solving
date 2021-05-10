# Programmers Lv2 타겟 넘버

- 날짜: 2021/05/10
- 문제 유형 : DFS, 재귀함수

## 문제
[문제 링크](https://programmers.co.kr/learn/courses/30/lessons/43165)

## Code
```swift
func solution_PRO_43165_타겟넘버(_ numbers:[Int], _ target:Int) -> Int {
    
    var answer = 0
    
    func search(index : Int, sum : Int){
        if index == numbers.count {
            if sum == target { answer += 1 }
            return
        }
        search(index: index + 1, sum: sum + numbers[index])
        search(index: index + 1, sum: sum - numbers[index])
    }
    search(index: 0, sum: 0)
    return answer
}
```

## Complexity
N : number 배열의 크기

각 배열의 요소마다 +, - 즉, 2번의 연산이 일어나야 하므로 시간 복잡도는  O(2^N)이다.