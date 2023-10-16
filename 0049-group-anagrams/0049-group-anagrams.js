/**
 * @param {string[]} strs
 * @return {string[][]}
 */
var groupAnagrams = function(strs) {
    let mp = {};
    for(let str of strs){
        let s = str.split('').sort().join('');
        if(!mp[s]) mp[s] = [];
        mp[s].push(str);
    }
    return Object.values(mp)
};