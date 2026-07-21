class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        string aug = "1"+s+"1";
        int i =0;
        vector<pair<char,int>>blocks;
        while(i<aug.size()){
            int j =i;
            while(j<aug.size() && aug[j]==aug[i]){
                j++;
            }
            int len =j-i;
            char ch = aug[i];
            blocks.push_back({ch,len});
            i=j;
        }
        int ones =0;
        for(char ch :s){
            if(ch=='1')
            ones++;
        }

        int gain =0;
        for(int i =1; i<blocks.size() ; i++){
            if(blocks[i].first=='1' && blocks[i-1].first == '0' && blocks[i+1].first =='0'){
                gain =max(gain , blocks[i-1].second+blocks[i+1].second);
            }
        }
        return ones+gain;
    }
};