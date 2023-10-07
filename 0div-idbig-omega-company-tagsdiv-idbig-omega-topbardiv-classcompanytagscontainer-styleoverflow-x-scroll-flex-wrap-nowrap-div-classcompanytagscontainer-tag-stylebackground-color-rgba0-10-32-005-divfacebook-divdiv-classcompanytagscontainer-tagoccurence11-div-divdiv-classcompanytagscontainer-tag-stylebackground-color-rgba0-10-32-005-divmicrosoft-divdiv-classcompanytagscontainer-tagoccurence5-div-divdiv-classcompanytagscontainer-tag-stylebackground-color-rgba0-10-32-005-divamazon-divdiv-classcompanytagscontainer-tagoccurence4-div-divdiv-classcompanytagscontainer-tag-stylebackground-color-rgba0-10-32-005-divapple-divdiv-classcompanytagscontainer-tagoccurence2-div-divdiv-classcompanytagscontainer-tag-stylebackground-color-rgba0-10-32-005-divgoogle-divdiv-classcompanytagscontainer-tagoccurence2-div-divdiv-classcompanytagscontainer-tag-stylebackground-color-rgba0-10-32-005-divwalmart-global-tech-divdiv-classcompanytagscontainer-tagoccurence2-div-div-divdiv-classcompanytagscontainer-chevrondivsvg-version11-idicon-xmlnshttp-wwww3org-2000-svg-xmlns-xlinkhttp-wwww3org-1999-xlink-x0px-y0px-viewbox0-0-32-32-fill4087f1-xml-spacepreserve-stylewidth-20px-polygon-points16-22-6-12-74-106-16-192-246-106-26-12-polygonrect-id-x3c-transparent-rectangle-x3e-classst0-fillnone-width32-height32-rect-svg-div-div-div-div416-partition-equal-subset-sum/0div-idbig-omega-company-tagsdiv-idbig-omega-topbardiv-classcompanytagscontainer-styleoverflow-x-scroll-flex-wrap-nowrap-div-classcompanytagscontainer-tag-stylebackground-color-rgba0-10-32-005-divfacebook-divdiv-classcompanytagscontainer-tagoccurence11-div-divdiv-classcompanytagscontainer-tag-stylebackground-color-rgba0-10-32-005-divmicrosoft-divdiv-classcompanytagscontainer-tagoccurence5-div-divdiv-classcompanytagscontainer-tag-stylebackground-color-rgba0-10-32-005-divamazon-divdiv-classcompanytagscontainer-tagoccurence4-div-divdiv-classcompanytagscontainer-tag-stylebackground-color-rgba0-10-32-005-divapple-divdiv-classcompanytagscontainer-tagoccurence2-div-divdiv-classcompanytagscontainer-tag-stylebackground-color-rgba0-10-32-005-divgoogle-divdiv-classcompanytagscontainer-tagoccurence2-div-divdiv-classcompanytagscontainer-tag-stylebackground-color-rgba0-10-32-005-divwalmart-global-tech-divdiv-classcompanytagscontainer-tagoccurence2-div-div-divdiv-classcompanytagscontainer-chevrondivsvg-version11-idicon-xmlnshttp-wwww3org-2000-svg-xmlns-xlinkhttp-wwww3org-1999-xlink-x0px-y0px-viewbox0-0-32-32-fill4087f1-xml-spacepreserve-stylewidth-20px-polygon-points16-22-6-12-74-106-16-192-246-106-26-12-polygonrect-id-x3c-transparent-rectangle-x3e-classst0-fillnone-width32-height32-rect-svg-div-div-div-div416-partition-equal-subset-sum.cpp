class Solution {
public:
    bool solve(vector<int> &nums , int target , int i , vector<vector<int>> &dp){
        if(target==0) return true;
        if(i==nums.size() || target<0 ) return false;
        if(dp[i][target]!=-1) return dp[i][target];
        int take = solve(nums , target-nums[i] , i+1 , dp);
        int notTake = solve(nums , target , i+1 , dp);
        return dp[i][target] = take || notTake; 
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        int target = sum/2;
        if(sum%2!=0) return false;
        vector<vector<int>> dp(n+1 , vector<int>(target+1 , -1));
        return solve(nums , target , 0 , dp);
    }
};