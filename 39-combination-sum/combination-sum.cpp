class Solution {
public:
    void f(int index , int target , vector<int> &a , vector<vector<int>> & ans , vector<int> & ds){
        if(index == a.size()){
            if(target==0){
            ans.push_back(ds);
        }
        return;
        }
        
        f(index +1 , target , a, ans , ds);  // notpick

        if(a[index] <= target ){
            ds.push_back(a[index]);
            f(index , target -a[index] , a , ans , ds);             // pick
            ds.pop_back();              
        }

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        f( 0 , target , candidates , ans ,ds);
        return ans;
    }
};