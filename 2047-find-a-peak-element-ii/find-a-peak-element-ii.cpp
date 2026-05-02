class Solution {
public:
    int max(vector<vector<int>>&nums,int col){
        int n = nums.size();
        int max_value =INT_MIN;
        int index =-1;
        for(int i = 0;i<n; i++){
            if(nums[i][col]>max_value){
                max_value=nums[i][col];
                index=i;
            }
        
        }
        return index;
    }


    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int low = 0 ,high = m-1;
        while(low<=high){
            int mid =(low+high)/2;

            int row =max(mat,mid);

            int left = (mid-1 >=0) ? mat[row][mid-1] : INT_MIN;
            int right = (mid+1 <m) ? mat[row][mid+1] :INT_MIN;

            if(mat[row][mid]>left && mat[row][mid]>right) return {row,mid};
            else if(mat[row][mid]>left) low =mid +1;
            else high = mid -1;


        }
        return {-1,-1};
    }
};