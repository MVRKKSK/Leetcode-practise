/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
    let i=0;
    let j=0;
    let mp = {};
    let counter = 0;
    let ans = 0;
    while(j<s.length){
        if(!mp[s[j]]){
            mp[s[j]] = 1;
            counter++;
            j++;
        }
        else if(mp[s[j]]===0){
            mp[s[j]]++;
            j++;
        }
        else{
            mp[s[i]]=0;
            counter--;
            i++;
        }
        ans = Math.max(counter , ans);
    }
    return ans;
};