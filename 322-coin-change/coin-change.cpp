class Solution {
public:
    int f(int ind ,int target , vector<int>&a, vector<vector<int>>&dp){
        if(ind==0){
            if(target%a[ind]==0) return target/a[ind];
            else return 1e9;
        }
        if(dp[ind][target]!=-1) return dp[ind][target];
        int nottake = f(ind-1,target,a,dp);
        int take =INT_MAX;
        if(target>=a[ind]) take = 1 + f(ind,target-a[ind],a,dp);
        return dp[ind][target] = min(take , nottake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n =coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans = f(n-1,amount,coins,dp);
        
        if(ans>=1e9) return -1;
        return ans;
    }
};