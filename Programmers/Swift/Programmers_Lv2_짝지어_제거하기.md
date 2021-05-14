# Programmers Lv2 짝지어 제거하기

- 날짜: 2021/05/14
- 문제 유형 : Stack

## 문제
[문제 링크](https://programmers.co.kr/learn/courses/30/lessons/12973)

## Code
```swift
func solution_PRO_12973_짝지어_제거하기(_ s:String) -> Int{

    var temp = [Character]()
    
    s.forEach { char in
        if temp.last == char {
            temp.removeLast()
        } else {
            temp.append(char)
        }
    }
    return temp.isEmpty ? 1 : 0
}
```

## Complexity
- N : 문자열의 길이

`append`, `removeLast`의 시간 복잡도는 O(1)
모든 문자열에 대하여 탐색해야하므로 시간복잡도는 **O(N)**

주어진 `string`을 Character Array로 바꾸면 효율성 테스트에서 시간초과 발생  
주어진 `string`에 대하여 바로 `forEach`문으로 탐색을 시도해야만 시간초과를 막을 수 있음