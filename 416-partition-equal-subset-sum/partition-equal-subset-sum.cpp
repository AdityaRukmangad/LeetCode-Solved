class Solution {
public: 
    int f(int ind , int target , vector<int> &a , vector<vector<int>> &dp){
        if(target ==0) return true;
        if(ind == 0) return a[ind]== target;
        if(dp[ind][target]!=-1) return dp[ind][target];
        bool nottake = f(ind -1 , target , a , dp);
        bool take = false;
        if(target>=a[ind]) take = f(ind -1 , target-a[ind],a,dp);
        return dp[ind][target] = take|nottake;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum=0;
        for(int i = 0;i<n;i++){
            sum+=nums[i];
        }
        int S=sum/2;
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        if(sum%2==1)  return false;
        else return f(n-1,S,nums,dp);
    }
};