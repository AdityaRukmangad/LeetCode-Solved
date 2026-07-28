class Solution {
public:
    string smallestPalindrome(string s) {
        unordered_map<char,int>mp;
        for(char c:s){
        mp[c]++;
        }
        string left ="";
        char mid ='\0';
        for(char ch = 'a' ; ch<='z' ; ch++){
            left.append(mp[ch]/2,ch);
            if(mp[ch]%2==1)
            mid=ch;
            
        }
        string right = left ;
        reverse(right.begin(),right.end());
        if(mid!='\0')
        return left + string(1, mid) + right;
        else return left+right;
        
    }
};