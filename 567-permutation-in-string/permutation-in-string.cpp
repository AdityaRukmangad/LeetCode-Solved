class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> freq1(26,0);
        vector<int> freq2(26,0);
        for(int i=0 ; i<s1.length();i++){
            freq1[s1[i]-'a']++;
        }
        int left = 0;
        for(int right =0; right < s2.length();right++){
            freq2[s2[right]-'a']++;
            if(right -left+1 > s1.length()){
                freq2[s2[left]-'a']--;
                left++;
            }
            if(freq1==freq2) return true;
            
        }
        
        return false;
    }
};