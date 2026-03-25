class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n =prices.size();
        int min=INT_MAX,profit=0;
        for (int i=0;i<n;i++){
            if(prices[i]<min){
                min=prices[i];
            }
            profit = max(prices[i]-min,profit);
        }
        return profit; 
    }
};