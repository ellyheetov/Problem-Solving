# Programmers Lv2 JadenCase 문자열 만들기

- 날짜: 2021/04/02

## 문제
[문제 링크](https://programmers.co.kr/learn/courses/30/lessons/12951)

## Code
```swift
func solution(_ s:String) -> String {
    return s.components(separatedBy: " ")
        .map{ $0.lowercased() }
        .map{ $0.prefix(1).uppercased() + $0.dropFirst()}
        .joined(separator: " ")
}
```
```swift
import Foundation 

func solution(_ s:String) -> String {
    return s.components(separatedBy: CharacterSet.whitespaces)
        .map{ $0.prefix(1).uppercased() + $0.lowercased().dropFirst()}
        .joined(separator: " ")
}
```

## Complexity
N : 문자열의 길이
- `lowercased()`, `uppercased()` : O(n)
- `dropFirst()` : RandomAccess가 가능하므로 O(1)
- `map()` : O(N)

문자열을 분리한 이후, map을 사용하여 각 글자를 확인하며 수정한다.
모든 글자를 확인해야하고, 이때 발생하는 비용은 **O(N)** 이다.

## Split 함수

- 공백 문자를 기준으로 split 하는 경우

    ex) "  hello m y friend "
    - `splited(seperatedBy : " ")` -> ["hello", "m", "y", "firend"]
    - `s.components(separatedBy: " ")` -> ["", "hello", "m", "y", "firend", ""]