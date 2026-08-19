class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.length();
        int n = t.length();
        unordered_map<char,int>freq1;
        unordered_map<char,int>freq2;
        for(int right =0 ; right <n ; right++){
            freq1[t[right]]++;
        }
        int left =0;
        int count=0;
        int minlen = INT_MAX;
        int start = 0;
        for(int right = 0; right <m ; right ++){
            freq2[s[right]]++;
            if(freq2[s[right]]<=freq1[s[right]]){
                count++;
            }
            while(count==n){
                if(right - left + 1 < minlen) {
                minlen = right - left + 1;
                start = left;
            } 
                freq2[s[left]]--;
                if(freq2[s[left]]< freq1[s[left]]){
                    count--;
                }
                left++;
            }
                  
        }
        if(minlen == INT_MAX) return "";
        return s.substr(start, minlen);

    }
};