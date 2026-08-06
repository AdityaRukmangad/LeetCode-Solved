class Solution {
public:
    int digitproduct(int n ){
        string s = to_string(n);
        int product =1;
        for(char c : s){
            product *= (c -'0');
        }
        return product;
    }
    int smallestNumber(int n, int t) {
        while(true){
            if(digitproduct(n)%t==0)
            return n;
            n++;
        }
    }
};