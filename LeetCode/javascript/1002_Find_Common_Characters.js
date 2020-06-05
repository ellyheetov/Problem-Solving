/**
 * @param {string[]} A
 * @return {string[]}
 */
var comonChars = function (A) {
    let common = A[0].split('').filter(char =>{
        for(let index = 0;index < A.length;index++){
            if(!A[index].includes(char)) return false;
            A[index] = A[index].replace(char,'');
        }
        return true;
    })
    return common;
};
const A = ["bella","label","roller"];
console.log(comonChars(A));