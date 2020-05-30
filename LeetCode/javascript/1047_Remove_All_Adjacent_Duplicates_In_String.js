/**
 * @param {string} S
 * @return {string}
 */
var removeDuplicates = function(S) {
    
    let answer =[];
    for(const c of S){
        if(answer.length === 0){
            answer.push(c);
            continue;
        }
        if(answer[answer.length -1] == c)
            answer.pop();
        else{
            answer.push(c);
        }
    }
    return answer;
};