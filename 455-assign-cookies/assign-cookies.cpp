class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int m = g.size();
        int n = s.size();
       sort(g.begin(),g.end());
       sort(s.begin(),s.end());
       int left = 0;
       int right = 0;
       while(left<n && right<m){
        if(s[left]>=g[right]) {       
        right++;
        }
        left++;
       } 
       return right;
    }
};