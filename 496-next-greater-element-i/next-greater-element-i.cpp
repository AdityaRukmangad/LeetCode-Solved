class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>st;
        
        int s = nums2.size();
        int m = nums1.size();
        vector<int>ans(s);
        for(int i = s-1 ; i>=0 ; i--){
            while(!st.empty() && st.top()<=nums2[i]){
                st.pop();
            }
            if(st.empty())
            ans[i] = -1;
            else
            ans[i] = st.top();
            st.push(nums2[i]);
        }
        unordered_map<int,int>mp;
        vector<int>res;
        for(int i = 0; i < s; i++){
            mp[nums2[i]] = ans[i];
        }              
        for(int x : nums1){
            res.push_back(mp[x]);
        }
        
        return res;
    }
};