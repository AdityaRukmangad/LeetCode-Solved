class Solution {
public:
    static bool compare(pair<char,int>a,pair<char,int>b){
        return a.second > b.second;
    }
    string frequencySort(string s) {
        unordered_map<char,int> freq;
        for(char c:s){
            freq[c]++;
        }
        vector<pair<char,int>> vec;

        for(auto x:freq){
            vec.push_back(x);
        }
        sort(vec.begin(), vec.end(), compare);

        string ans= "";
        for(auto x : vec ){
            for(int i =0 ;i<x.second;i++){
                ans +=x.first;
        }
    }
    return ans;
    }

};