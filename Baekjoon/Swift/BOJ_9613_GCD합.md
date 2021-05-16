# 백준 9613 GCD 합

- 날짜: 2021/05/16
- 문제 유형 : Math

## 문제
[문제 링크](https://www.acmicpc.net/problem/9613)


## Code

```swift
func solution_BOJ_9613_GCD합(){
    
    func gcd(x: Int, y: Int) -> Int{
        if y == 0 {
            return x
        }
        return gcd(x: y, y: x%y)
    }
    func sumOfGCD(array : [Int]) -> Int {
        var result = 0
        for i in 0..<array.count {
            for j in (i+1)..<array.count {
                let x = max(array[i], array[j])
                let y = min(array[i], array[j])
                result += gcd(x: x, y: y)
            }
        }
        return result
    }
    
    let testCase = Int(readLine()!)!
    for _ in 0..<testCase {
        var input = readLine()!.split(separator: " ").map{ Int($0)! }
        input.removeFirst()
        let answer = sumOfGCD(array: input)
        print(answer)
    }
}
```

# GCD란?

- 2개의 자연수의 최대 공약수를 구하는 알고리즘

유클리드 알고리즘((Euclidean algorithm)) 이라고 불린다. 비교대상의 두 개의 자연수 a와 b에서(단 a>b) a를 b로 나눈 나머지를 r이라고 했을때 GCD(a, b) = GCD(b, r)과 같고 "r이 0이면 그때 b가 최대공약수이다."라는 원리를  활용한 알고리즘이다.

ex) GCD(24,16) -> GCD(16,8) -> GCD(8,0) : 최대공약수 = 8

## 구현
### 재귀 함수 활용
```c++
int GCD(int a, int b)
{
    if(b==0)return a;
    else return GCD(b,a%b);
}
```

### 반복문 활용
```c++
int GCD(int a,int b){
    while(1){
        int r = a%b;
        if(r==0) return b;
		
        a = b;
        b = r;
    }
}
```
