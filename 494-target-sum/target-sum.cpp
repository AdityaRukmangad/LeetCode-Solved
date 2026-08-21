class Solution {
public: 
    int f(int ind , int target , vector<int>&a , vector<vector<int>>&dp){
        if(ind ==0){
            if(target==0 && a[0]==0) return 2;
            if(target==0 || a[0]==target)return 1;
            return 0;
        }
        if(dp[ind][target]!=-1) return dp[ind][target];
        int nottake = f(ind -1 , target , a, dp);
        int take = 0;
        if(target>=a[ind])
        take = f(ind-1 , target -a[ind],a,dp);
        return dp[ind][target] = nottake + take;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totalsum =0;
        for(int i=0;i<n;i++){
            totalsum+=nums[i];
        }
        if(totalsum - target <0) return 0;
        if((totalsum - target )%2!=0) return 0;
        int s2 = (totalsum - target)/2;
        vector<vector<int>>dp(n,vector<int>(s2+1,-1));
        return f(n-1,s2,nums,dp);
    }

};