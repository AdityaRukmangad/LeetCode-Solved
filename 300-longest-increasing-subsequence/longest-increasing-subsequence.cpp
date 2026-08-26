class Solution {
public: 
    int f(int ind , int prev , vector<int>&a , vector<vector<int>>&dp){
        int n = a.size();
        if(ind == n ) return 0;
        if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];
        int nottake = 0 + f(ind +1 , prev , a ,dp );
        int take = 0;
        if(prev ==-1 || a[ind ] > a[prev ]){
        take = 1 + f(ind +1 , ind , a ,dp );
        }
        return dp[ind][prev+1] =  max(take , nottake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n ,vector<int>(n+1 ,-1));
        return f(0, -1 ,nums ,dp);
    }
};