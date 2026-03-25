class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>A(n);

        int posindex =0;
        int negindex=1;
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                A[posindex] = nums[i];
                posindex +=2;
            }
            else{
            A[negindex] = nums[i];
            negindex +=2;
        }
    }
        return A;
    }
};