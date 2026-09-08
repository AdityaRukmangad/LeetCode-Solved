class Solution {
public:
    int countCommas(int n) {
        int comma =0;
        if(n >= 1000)
        comma+= n -1000 +1;
        // if(n 100000)
        // comma+= n - 1000000 +1;
        return comma;
    }
        
};