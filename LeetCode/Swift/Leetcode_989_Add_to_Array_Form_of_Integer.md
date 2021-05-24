# LeetCode 989. Add to Array-Form of Integer

- 날짜: 2021/05/24
- 문제 유형 : Math

## 문제
[문제 링크](https://leetcode.com/problems/add-to-array-form-of-integer/)

## 내 코드

```swift
func addToArrayForm(_ num: [Int], _ k: Int) -> [Int] {
        
    var num = num
    var target = String(k).map{ String($0)}.map{ Int($0)! }
        
    while target.count < num.count {
        target.insert(0, at: 0)
    }
    while num.count < target.count {
        num.insert(0, at: 0)
    }
    var carry = 0
    var answer = [Int]()
    
        
    for (item1, item2) in zip(num, target).reversed() {
        let temp = carry + item1 + item2
        answer.append(temp%10)
        carry = temp/10
    }
    if carry != 0 {
        answer.append(carry)
    }
    return answer.reversed()
}
```

1. input으로 들어온 k를 숫제 배열로 바꾸어 준다.
2. 배열의 크기를 맞춰주기 위해, 0을 삽입한다.
3. 각 자리수를 순회하며 carry를 계산한다.
4. 배열을 뒤집어 반환한다.


## 개선한 코드
```swift
func addToArrayForm(_ num: [Int], _ k: Int) -> [Int] {
    var num = num, k = k
    var index = num.count
    
    while index > 0 && k > 0 {
        index -= 1
        let sum = num[index] + k
        num[index] = sum % 10
        k = sum / 10
    }
    while k > 0 {
        num.insert(k%10, at: 0)
        k /= 10
    }
    return num
}
```
인풋으로 들어온 `k` 자체를 carry로 보고, 통째로 더한다.
배열의 크기를 맞추기 위해 메모리를 더 할당할 필요가 없으며, 2번의 `while`문 만으로 해결할 수 있다.

# Complexity Analysis

- N: num 배열의 길이

Time Complexity: O(max(N, log K))

Space Complexity: O(max(N,logK))

K에 대해서 계속 반으로 나누고 있으므로 이진탐색으로 볼 수 있다. 때문에 복잡도는 K가 아닌 logK를 가진다.