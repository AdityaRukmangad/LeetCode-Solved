class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
    
        long long sum = 0;
        int l = 0 , res= 0;
         for (int r = 0 ; r < n ; r++) {
            sum +=nums[r];

            while((long long)(r-l+1)*nums[r]-sum>k){
                sum-=nums[l];
                l++;
                
            }
            res= max(res,r-l+1);
         }
         return res;
    }

};