class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left=0 ;
        int sum=0;
        int ans =INT_MAX;
        int n = nums.size();
        for(int right =0 ; right <n; right++){
            sum+=nums[right];
            while(sum>=target){                
                int length = right  -left +1;
                ans =min(ans,length);
                sum-=nums[left];
                left++;
            }       
            
            
        }
        if (ans==INT_MAX) return 0;
        return ans;
        
    }
};