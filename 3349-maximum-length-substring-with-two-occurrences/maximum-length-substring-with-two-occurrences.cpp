class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char,int>freq;
        int n =s.length();
        int left=0;
        int maxlen=0;
        for(int right =0 ; right < n ; right++ ){
            freq[s[right]]++;
            while(freq[s[right]]>2){
                freq[s[left]]--;            
                left++;
                
            }
            maxlen = max(maxlen, right-left+1);
        }
        return maxlen;
    }
};