class Solution {
public: 
    int f ( int ind , int buy , vector<int>&a , vector<vector<int>>&dp){
        int n = a.size();
        int profit = INT_MIN;
        if(ind == n ) return 0;
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        if(buy){
            profit  =  max( -a[ind] + f(ind+1 , 0 ,a ,dp) , 0 + f(ind +1 , 1 ,a ,dp));
        }
        else 
        profit =  max( a[ind] + f(ind +1 , 1 ,a ,dp ) , 0 + f(ind +1 , 0 , a ,dp ));
        return dp[ind][buy] = profit ;

    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n ,vector<int>(2 ,-1));
        return f(0,1,prices ,dp );
    }
};