class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n =nums.size();
        int maxp =nums[0];
        int minp =nums[0];
        int ans=nums[0];
        for(int i =1;i<n ; i++){
            
            if(nums[i]<0)
            swap(maxp,minp);
            
            int tempmax = maxp;
            int tempmin = minp;

            maxp = max(nums[i] ,max(tempmax*nums[i],tempmin*nums[i]));
            minp = min(nums[i] ,min(tempmin*nums[i],tempmax*nums[i]));
            ans = max(maxp,ans);


        }
        return ans;

    }
};