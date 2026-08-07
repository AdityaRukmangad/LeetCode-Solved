class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum=0;
        int n =nums.size();
        for(int i =0 ; i<k ; i++){
            sum+=nums[i];
        }
        int maxi =sum;
        for(int right = k ; right<n; right++ ){
            sum+=nums[right];
            sum-=nums[right-k];
            maxi = max(maxi,sum);
        }
        
        return (double)maxi/k;
    }
};