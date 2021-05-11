# Programmers Lv2 카펫

- 날짜: 2021/05/11
- 문제 유형 : 완전탐색

## 문제
[문제 링크](https://programmers.co.kr/learn/courses/30/lessons/42842)

## Code
```swift
func solution(_ brown:Int, _ yellow:Int) -> [Int] {
    func getDivisors(number : Int) -> [Int] {
        var result = [Int]()
        for num in 2...Int(sqrt(Double(number))) {
            if number % num == 0 {
                result.append(num)
            }
        }
        return result
    }

    let total = brown + yellow
    let divisors = getDivisors(number: total)
    
    for divisor in divisors {
        let d1 = divisor
        let d2 = total/divisor
        if (d1 - 2) * (d2 - 2) == yellow {
            return [d2,d1]
        }
    }
    return []
}
```

## Complexity
**O(N)**, (N : brown + yellow)



## 추가
### 약수의 개수 구하기
```swift
 func getDivisorCount(number : Int) -> Int {
     var number = number
     var count = 1
     var info = [Int](repeating: 0, count: number)
     
     for divisor in 2..<number {
         while(number % divisor == 0){
             number = number / divisor
             info[divisor] += 1
         }
     }
     info.filter{ $0 != 0}.forEach{ value in
         count *= (value+1)
     }
     return count
 }
 ```