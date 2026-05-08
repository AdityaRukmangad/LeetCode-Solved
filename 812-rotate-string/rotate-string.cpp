class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length()!=goal.length()) return false;
        string twice = s+s;
        if(twice.find(goal) == string::npos) return false;
        else 
        return true;
    }
};