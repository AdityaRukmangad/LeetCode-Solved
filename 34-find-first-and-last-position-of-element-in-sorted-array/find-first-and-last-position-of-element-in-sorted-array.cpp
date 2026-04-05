class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int low =0,high = n-1;
        int first_occ =-1;
        while (low<=high){
            int mid =(low+high)/2;
            if (nums[mid]==target){
                first_occ = mid;
                high = mid-1;
            }
            else if(nums[mid]>target){
                high = mid -1;
            }
            else
            low= mid+1;
        }
    
        int last_occ =-1;
        low =0,high = n-1;
        while (low<=high){
            int mid =(low+high)/2;
            if (nums[mid]==target){
                last_occ = mid;
                low = mid+1;
            }
            else if(nums[mid]>target){
                high = mid -1;
            }
            else
            low= mid+1;
        }
        return {first_occ,last_occ} ;

    }
};