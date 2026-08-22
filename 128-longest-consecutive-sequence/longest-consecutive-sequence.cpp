class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int> st(nums.begin(), nums.end());

        int ans = 0;

        // Check every number
        for(int x : st) {
            if(st.count(x-1)==0){
                int len =1;
                while(st.count(x+len)){
                    len++;
                }
                ans=max(ans,len);

            }

            
        }

        return ans;
    }
};