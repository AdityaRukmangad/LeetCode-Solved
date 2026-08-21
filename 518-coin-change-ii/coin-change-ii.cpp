class Solution {
public:
    int f(int ind, int t ,vector<int>&a,vector<vector<int>>&dp){
        if(ind==0){
            return (t%a[ind]==0);
        }
        if(dp[ind][t]!=-1) return dp[ind][t];
        int nottake = f(ind-1,t,a,dp);
        int take =0;
        if(t>=a[ind]) take = f(ind,t-a[ind],a,dp);
        return dp[ind][t]= take + nottake;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return f(n-1,amount,coins,dp);
    }
};