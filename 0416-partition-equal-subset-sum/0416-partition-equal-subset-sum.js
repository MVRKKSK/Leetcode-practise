/**
 * @param {number[]} nums
 * @return {boolean}
 */
let solve = function(nums, target, i, dp) {
    if (target === 0) {
        return true;
    }
    if (i === nums.length - 1 || target < 0) {
        return false;
    }
    if (dp[i][target] !== undefined) {
        return dp[i][target];
    }
    let take = solve(nums, target - nums[i], i + 1, dp);
    let notTake = solve(nums, target, i + 1, dp);
    return dp[i][target] = take || notTake;
};

var canPartition = function(nums) {
    let sum = nums.reduce((acc, curr) => acc + curr, 0);
    if (sum % 2 !== 0) {
        return false;
    }
    let target = sum / 2;
    let dp = new Array(nums.length);
    for (let i = 0; i < nums.length; i++) {
        dp[i] = new Array(target + 1);
    }
    return solve(nums, target, 0, dp);
};