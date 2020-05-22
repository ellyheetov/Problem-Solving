
function solution(d, budget) {
    let answer = 0;
    var count = 0;

    d.sort((a,b)=>(a-b)).forEach(element => {
        if(element <= budget){
            budget -= element;
            answer++;
        }
    });
   return answer;
}
console.log(solution([1,2,3,4,5],9));