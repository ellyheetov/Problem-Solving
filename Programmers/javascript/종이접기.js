
function nextPattern(pattern){

    let left = pattern.slice();
    let right = pattern.slice().reverse().map(x => (Number)(!x));

    return [].concat(left).concat(0).concat(right);
}

function solution(n) {

    let answer = [0];
    const size = Math.pow(2,n) -1;

    while(answer.length !== size){
        answer = nextPattern(answer);
    }    
    return answer;
}
console.log(solution(3));