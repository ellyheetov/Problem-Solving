/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
var intersect = function(nums1, nums2) {
    const map = {};
    nums1.forEach(x=>map[x] ? map[x]++ : map[x] = 1);

    return nums2.filter(x=>{
        if(map[x]){
            map[x]--;
            return true;
        }
        return false;
    })
};
const num1 = [1,2,2,1];
const num2 = [2];
console.log(intersect(num1,num2));
