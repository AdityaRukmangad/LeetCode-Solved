class Solution {
public:
    void f( int ind , int target , vector<int > & a , vector<vector<int>> & ans , vector<int > & ds){
        
            if(target == 0){
                ans.push_back(ds);
                return;
            }
            
        
        for(int i = ind ; i<a.size() ; i++){
            if(i > ind && a[i]==a[i-1]) continue;
            if(a[i] > target ) break;
            ds.push_back(a[i]);
            f(i +1 , target -a[i] ,a , ans ,ds);
            ds.pop_back();
        
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin() , candidates.end());
        vector<int>ds;
        vector<vector<int>>ans;
        f(0 , target , candidates , ans ,ds);
        return ans;
    }
};